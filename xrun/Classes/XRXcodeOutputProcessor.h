/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2017 Jean-David Gadina - www.xs-labs.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @header      XRXcodeOutputProcessor.h
 * @copyright   (c) 2017, Jean-David Gadina - www.xs-labs.com
 */

#import <Foundation/Foundation.h>
#import <ShellKit/ShellKit.h>

@class XRXcodeMessageMatcher;

NS_ASSUME_NONNULL_BEGIN

@interface XRXcodeOutputProcessor: SKObject < SKTaskDelegate >

@property( atomic, readwrite, assign  ) BOOL       verbose;
@property( atomic, readonly           ) BOOL       hasWarnings;
@property( atomic, readonly           ) BOOL       hasErrors;
@property( atomic, readonly           ) BOOL       hasAnalyzerWarnings;
@property( atomic, readonly           ) BOOL       hasStandardErrorOutput;
@property( atomic, readonly, nullable ) NSString * lastOutput;
@property( atomic, readonly           ) BOOL       errorDetectedOnLastOutput;
@property( atomic, readonly, nullable ) NSString * standardErrorOutput;

+ ( instancetype )defaultOutputProcessor;
- ( instancetype )initWithMessageMatchers:  ( NSArray< XRXcodeMessageMatcher * > * )messages
                  warningMatchers:          ( NSArray< XRXcodeMessageMatcher * > * )warnings 
                  errorMatchers:            ( NSArray< XRXcodeMessageMatcher * > * )errors
                  NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
