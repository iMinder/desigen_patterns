//
//  Creater.m
//  FactoryParttern_OC
//
//  Created by jackie on 15/3/24.
//  Copyright (c) 2015年 jackie. All rights reserved.
//

#import "Creater.h"
#import "Product.h"

@implementation Creater

- (Product *)FactoryMethod
{
    NSLog(@"这是抽象方法，不做任何事情");
    return nil;
}

@end

@implementation CreaterA

- (Product *)FactoryMethod
{
    ProductA *productA = [ProductA new
                          ];
    return productA;
}

@end
