/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#import <Foundation/Foundation.h>

#import "TProtocol.h"
#import "TProtocolFactory.h"
#import "TApplicationError.h"
#import "TProtocolError.h"
#import "TProtocolUtil.h"
#import "TProcessor.h"
#import "TBase.h"
#import "TAsyncTransport.h"
#import "TBaseClient.h"


typedef NS_ENUM(SInt32, ChatRoomServiceClientType) {
  ChatRoomServiceClientTypePC = 1,
  ChatRoomServiceClientTypeAndriodPhone = 2,
  ChatRoomServiceClientTypeAndriodPad = 3,
  ChatRoomServiceClientTypeiPhone = 4,
  ChatRoomServiceClientTypeiPad = 5
};

typedef NS_ENUM(SInt32, ChatRoomServiceMessageType) {
  ChatRoomServiceMessageTypeString = 1,
  ChatRoomServiceMessageTypeemoji = 2,
  ChatRoomServiceMessageTypeimage = 3,
  ChatRoomServiceMessageTypefile = 4
};

typedef NS_ENUM(SInt32, ChatRoomServiceStatusType) {
  ChatRoomServiceStatusTypeOffline = 0,
  ChatRoomServiceStatusTypeOnline = 1,
  ChatRoomServiceStatusTypeBusy = 2,
  ChatRoomServiceStatusTypeHidden = 3
};

typedef NS_ENUM(SInt32, ChatRoomServiceErrorCode) {
  ChatRoomServiceErrorCodeOK = 0,
  ChatRoomServiceErrorCodeNetError = 1,
  ChatRoomServiceErrorCodeUserNotExist = 100,
  ChatRoomServiceErrorCodePasswordError = 101,
  ChatRoomServiceErrorCodeUserDisable = 102,
  ChatRoomServiceErrorCodeUserExist = 103,
  ChatRoomServiceErrorCodeUserOffline = 200
};

@interface ChatRoomServiceSessionInfo : NSObject <TBase, NSCoding, NSCopying> 

@property (strong, nonatomic) NSString * sessionId;
@property (assign, nonatomic) BOOL sessionIdIsSet;
- (void) unsetSessionId;


- (instancetype) initWithSessionId: (NSString *) sessionId;

@end

@interface ChatRoomServiceLoginRequest : NSObject <TBase, NSCoding, NSCopying> 

@property (strong, nonatomic) NSString * userName;
@property (assign, nonatomic) BOOL userNameIsSet;
- (void) unsetUserName;

@property (strong, nonatomic) NSString * password;
@property (assign, nonatomic) BOOL passwordIsSet;
- (void) unsetPassword;

@property (strong, nonatomic) NSString * machineCode;
@property (assign, nonatomic) BOOL machineCodeIsSet;
- (void) unsetMachineCode;

@property (assign, nonatomic) ChatRoomServiceClientType type;
@property (assign, nonatomic) BOOL typeIsSet;
- (void) unsetType;


- (instancetype) initWithUserName: (NSString *) userName password: (NSString *) password machineCode: (NSString *) machineCode type: (ChatRoomServiceClientType) type;

@end

@interface ChatRoomServiceLoginResponse : NSObject <TBase, NSCoding, NSCopying> 

@property (assign, nonatomic) BOOL isSuccess;
@property (assign, nonatomic) BOOL isSuccessIsSet;
- (void) unsetIsSuccess;

@property (strong, nonatomic) NSString * displayName;
@property (assign, nonatomic) BOOL displayNameIsSet;
- (void) unsetDisplayName;

@property (assign, nonatomic) SInt32 userId;
@property (assign, nonatomic) BOOL userIdIsSet;
- (void) unsetUserId;

@property (strong, nonatomic) NSString * sessionId;
@property (assign, nonatomic) BOOL sessionIdIsSet;
- (void) unsetSessionId;

@property (assign, nonatomic) ChatRoomServiceErrorCode errorCode;
@property (assign, nonatomic) BOOL errorCodeIsSet;
- (void) unsetErrorCode;


- (instancetype) initWithIsSuccess: (BOOL) isSuccess displayName: (NSString *) displayName userId: (SInt32) userId sessionId: (NSString *) sessionId errorCode: (ChatRoomServiceErrorCode) errorCode;

@end

@interface ChatRoomServiceRegisterRequest : NSObject <TBase, NSCoding, NSCopying> 

@property (strong, nonatomic) NSString * userName;
@property (assign, nonatomic) BOOL userNameIsSet;
- (void) unsetUserName;

@property (strong, nonatomic) NSString * password;
@property (assign, nonatomic) BOOL passwordIsSet;
- (void) unsetPassword;

@property (strong, nonatomic) NSString * displayName;
@property (assign, nonatomic) BOOL displayNameIsSet;
- (void) unsetDisplayName;

@property (strong, nonatomic) NSData * picture;
@property (assign, nonatomic) BOOL pictureIsSet;
- (void) unsetPicture;


- (instancetype) initWithUserName: (NSString *) userName password: (NSString *) password displayName: (NSString *) displayName picture: (NSData *) picture;

@end

@interface ChatRoomServiceUserInfo : NSObject <TBase, NSCoding, NSCopying> 

@property (strong, nonatomic) NSString * userName;
@property (assign, nonatomic) BOOL userNameIsSet;
- (void) unsetUserName;

@property (strong, nonatomic) NSString * displayName;
@property (assign, nonatomic) BOOL displayNameIsSet;
- (void) unsetDisplayName;

@property (strong, nonatomic) NSData * picture;
@property (assign, nonatomic) BOOL pictureIsSet;
- (void) unsetPicture;

@property (assign, nonatomic) SInt32 userId;
@property (assign, nonatomic) BOOL userIdIsSet;
- (void) unsetUserId;

@property (assign, nonatomic) ChatRoomServiceClientType type;
@property (assign, nonatomic) BOOL typeIsSet;
- (void) unsetType;

@property (assign, nonatomic) ChatRoomServiceStatusType status;
@property (assign, nonatomic) BOOL statusIsSet;
- (void) unsetStatus;


- (instancetype) initWithUserName: (NSString *) userName displayName: (NSString *) displayName picture: (NSData *) picture userId: (SInt32) userId type: (ChatRoomServiceClientType) type status: (ChatRoomServiceStatusType) status;

@end

@interface ChatRoomServiceMessageInfo : NSObject <TBase, NSCoding, NSCopying> 

@property (assign, nonatomic) SInt64 seqNo;
@property (assign, nonatomic) BOOL seqNoIsSet;
- (void) unsetSeqNo;

@property (assign, nonatomic) ChatRoomServiceMessageType type;
@property (assign, nonatomic) BOOL typeIsSet;
- (void) unsetType;

@property (strong, nonatomic) NSString * message;
@property (assign, nonatomic) BOOL messageIsSet;
- (void) unsetMessage;

@property (strong, nonatomic) NSString * emoji;
@property (assign, nonatomic) BOOL emojiIsSet;
- (void) unsetEmoji;

@property (strong, nonatomic) NSData * image;
@property (assign, nonatomic) BOOL imageIsSet;
- (void) unsetImage;

@property (strong, nonatomic) NSData * file;
@property (assign, nonatomic) BOOL fileIsSet;
- (void) unsetFile;

@property (assign, nonatomic) SInt32 srcUserId;
@property (assign, nonatomic) BOOL srcUserIdIsSet;
- (void) unsetSrcUserId;

@property (assign, nonatomic) SInt32 dstUserId;
@property (assign, nonatomic) BOOL dstUserIdIsSet;
- (void) unsetDstUserId;

@property (assign, nonatomic) BOOL isGroupChat;
@property (assign, nonatomic) BOOL isGroupChatIsSet;
- (void) unsetIsGroupChat;


- (instancetype) initWithSeqNo: (SInt64) seqNo type: (ChatRoomServiceMessageType) type message: (NSString *) message emoji: (NSString *) emoji image: (NSData *) image file: (NSData *) file srcUserId: (SInt32) srcUserId dstUserId: (SInt32) dstUserId isGroupChat: (BOOL) isGroupChat;

@end

@interface ChatRoomServiceGetUserListRequest : NSObject <TBase, NSCoding, NSCopying> 

@property (assign, nonatomic) SInt32 userId;
@property (assign, nonatomic) BOOL userIdIsSet;
- (void) unsetUserId;

@property (strong, nonatomic) NSString * userName;
@property (assign, nonatomic) BOOL userNameIsSet;
- (void) unsetUserName;

@property (strong, nonatomic) NSString * displayName;
@property (assign, nonatomic) BOOL displayNameIsSet;
- (void) unsetDisplayName;

@property (assign, nonatomic) ChatRoomServiceClientType type;
@property (assign, nonatomic) BOOL typeIsSet;
- (void) unsetType;

@property (assign, nonatomic) ChatRoomServiceStatusType status;
@property (assign, nonatomic) BOOL statusIsSet;
- (void) unsetStatus;


- (instancetype) initWithUserId: (SInt32) userId userName: (NSString *) userName displayName: (NSString *) displayName type: (ChatRoomServiceClientType) type status: (ChatRoomServiceStatusType) status;

@end

@interface ChatRoomServiceSendMessageResponse : NSObject <TBase, NSCoding, NSCopying> 

@property (assign, nonatomic) ChatRoomServiceErrorCode errorCode;
@property (assign, nonatomic) BOOL errorCodeIsSet;
- (void) unsetErrorCode;

@property (assign, nonatomic) SInt64 seqNo;
@property (assign, nonatomic) BOOL seqNoIsSet;
- (void) unsetSeqNo;


- (instancetype) initWithErrorCode: (ChatRoomServiceErrorCode) errorCode seqNo: (SInt64) seqNo;

@end

@interface ChatRoomServiceReceiveMessageRequest : NSObject <TBase, NSCoding, NSCopying> 

@property (assign, nonatomic) SInt64 seqNo;
@property (assign, nonatomic) BOOL seqNoIsSet;
- (void) unsetSeqNo;

@property (assign, nonatomic) SInt32 userId;
@property (assign, nonatomic) BOOL userIdIsSet;
- (void) unsetUserId;


- (instancetype) initWithSeqNo: (SInt64) seqNo userId: (SInt32) userId;

@end

FOUNDATION_EXPORT NSString *ChatRoomServiceStructErrorDomain;

