//
//  AnotherFactoryMethodWithProtocol.h
//  FactoryParttern_OC
//
//  Created by jackie on 15/3/24.
//  Copyright (c) 2015年 jackie. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol FactoryMethodInterface <NSObject>

- (void)operatinoA;
- (void)operatinoB;

@end
@interface AnotherFactoryMethodWithProtocol : NSObject<FactoryMethodInterface>


@end
