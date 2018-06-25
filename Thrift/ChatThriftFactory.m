//
//  ChatThriftFactory.m
//  Thrift
//
//  Created by zhangyx on 2018/6/20.
//  Copyright © 2018 zhangyx. All rights reserved.
//

#import "ChatThriftFactory.h"
#import "TSocketTransport.h"
#import "TBinaryProtocol.h"

#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)

@interface ChatThriftFactory () <ChatRoomServiceCallbackService>
@property (nonatomic, strong) dispatch_queue_t messageQueue;
@property (nonatomic, strong) dispatch_queue_t otherQueue;
@property (nonatomic, strong) ChatRoomServiceChatServiceClient *client;
@property (nonatomic, weak) TSocketTransport *socketT;
@property (nonatomic, assign) BOOL receiveCycle;
@end
ChatAPIMethod const kChartRoomLogin        = @"userLogin:error:";
ChatAPIMethod const kChartRoomRegister     = @"";
//ChartAPIMethod const kChartRoomGetUserList  = @"";

@implementation ChatThriftFactory
- (instancetype)init {
    if (self = [super init]) {
        self.messageQueue = dispatch_queue_create("messageQueue", DISPATCH_QUEUE_SERIAL);
        self.otherQueue = dispatch_queue_create("otherQueue", DISPATCH_QUEUE_SERIAL);
        
        [self connectServer];
    }
    return self;
}
- (void)connectServer {
    TSocketTransport *transport = [[TSocketTransport alloc] initWithHostname:@"10.1.22.197" port:9090];
    TBinaryProtocol *protocol = [[TBinaryProtocol alloc] initWithTransport:transport];
    ChatRoomServiceChatServiceClient *client = [[ChatRoomServiceChatServiceClient alloc] initWithProtocol:protocol];
    self.client = client;
    self.socketT = transport;
    self.receiveCycle = YES;
}
- (void)listen {
    dispatch_async(self.messageQueue, ^{
        ChatRoomServiceCallbackServiceProcessor *processor = [[ChatRoomServiceCallbackServiceProcessor alloc] initWithCallbackService:self];
        while (self.receiveCycle) {
            NSError *error;
            if ([processor processOnInputProtocol:[[TBinaryProtocol alloc] initWithTransport:self.socketT] outputProtocol:[[TBinaryProtocol alloc] initWithTransport:self.socketT] error:&error]) {
                if (error) {
                    break;
                }
                DLog(@"=---=");
            }
        }
    });
}
+ (instancetype)sharedFactory {
    static ChatThriftFactory *f;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        f = [[ChatThriftFactory alloc] init];
    });
    return f;
}
- (void)requestWithMethod:(ChatAPIMethod)method argument:(NSObject *)argument completed:(void (^)(NSObject *respose))completed {
    dispatch_async(self.otherQueue, ^{
        NSError *error;
        NSObject *r;
        SuppressPerformSelectorLeakWarning(r = [self.client performSelector:NSSelectorFromString(method) withObject:argument withObject:error]);
        dispatch_sync(dispatch_get_main_queue(), ^{
            completed(r);
        });
    });
}
- (BOOL)receiveMessage:(ChatRoomServiceMessageInfo *)message error:(NSError *__autoreleasing *)__thriftError {
    DLog(@"---");
    return YES;
}
- (void)dealloc {
    self.receiveCycle = NO;
}
@end
