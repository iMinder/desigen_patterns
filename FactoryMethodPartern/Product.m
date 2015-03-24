//
//  Product.m
//  FactoryParttern_OC
//
//  Created by jackie on 15/3/24.
//  Copyright (c) 2015年 jackie. All rights reserved.
//

#import "Product.h"

@implementation Product


- (void)product
{
    NSLog(@"这是产品抽象类，不实现任何东东");
}

@end

@implementation ProductA

-(void)product
{
    NSLog(@"这才是真正的产品类");
}

@end