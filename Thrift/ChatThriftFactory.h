//
//  ChatThriftFactory.h
//  Thrift
//
//  Created by zhangyx on 2018/6/20.
//  Copyright © 2018 zhangyx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ChatRoomServiceChatService.h"
#import "ChatRoomServiceCallbackService.h"

#ifdef DEBUG
#   define DLog(format, ...) NSLog((@"[file %s] [func %s] [line %d] " format), __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define DLog(...)
#endif

typedef NSString * ChatAPIMethod NS_EXTENSIBLE_STRING_ENUM;

extern ChatAPIMethod const kChartRoomLogin;
extern ChatAPIMethod const kChartRoomRegister;
extern ChatAPIMethod const kChartRoomGetUserList;
//extern ChartAPIMethod const kChartRoomsendMessage;
//extern ChartAPIMethod const kChartRoomLogin;
//extern ChartAPIMethod const kChartRoomLogin;

@interface ChatThriftFactory : NSObject
+ (instancetype)sharedFactory;
- (void)requestWithMethod:(ChatAPIMethod)method argument:(NSObject *)argument completed:(void (^)(NSObject *respose))completed;
- (void)listen;
@end
