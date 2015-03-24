//
//  Creater.h
//  FactoryParttern_OC
//
//  Created by jackie on 15/3/24.
//  Copyright (c) 2015年 jackie. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Product;
@class ProductA;

@interface Creater : NSObject

- (Product *)FactoryMethod;

@end

@interface CreaterA : Creater

- (Product *)FactoryMethod;

@end
