//
//  ViewController.m
//  Thrift
//
//  Created by zhangyx on 2018/6/13.
//  Copyright © 2018 zhangyx. All rights reserved.
//

#import "ViewController.h"
#import "ChatThriftFactory.h"
@interface ViewController ()
{}
@property (nonatomic, strong) ChatThriftFactory *fa;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    ChatThriftFactory *factory = [ChatThriftFactory sharedFactory];
    self.fa =factory;
    
}
- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    __weak typeof(ChatThriftFactory *) weakFa = self.fa;
    [self.fa requestWithMethod:kChartRoomLogin argument:[[ChatRoomServiceLoginRequest alloc] initWithUserName:@"123" password:@"123" machineCode:@"123" type:ChatRoomServiceClientTypeiPhone] completed:^(NSObject *respose) {
        DLog(@"%@", respose);
        [weakFa listen];
    }];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end 
