xrun
====

[![Build Status](https://img.shields.io/travis/macmade/xrun.svg?branch=master&style=flat)](https://travis-ci.org/macmade/xrun)
[![Coverage Status](https://img.shields.io/coveralls/macmade/xrun.svg?branch=master&style=flat)](https://coveralls.io/r/macmade/xrun?branch=master)
[![Issues](http://img.shields.io/github/issues/macmade/xrun.svg?style=flat)](https://github.com/macmade/xrun/issues)
![Status](https://img.shields.io/badge/status-active-brightgreen.svg?style=flat)
![License](https://img.shields.io/badge/license-mit-brightgreen.svg?style=flat)
[![Contact](https://img.shields.io/badge/contact-@macmade-blue.svg?style=flat)](https://twitter.com/macmade)  
[![Donate-Patreon](https://img.shields.io/badge/donate-patreon-yellow.svg?style=flat)](https://patreon.com/macmade)
[![Donate-Gratipay](https://img.shields.io/badge/donate-gratipay-yellow.svg?style=flat)](https://www.gratipay.com/macmade)
[![Donate-Paypal](https://img.shields.io/badge/donate-paypal-yellow.svg?style=flat)](https://paypal.me/xslabs)

## About

### xrun is a drop-in replacement for Apple's xcodebuild or Facebook's xctool

![xrun](Assets/xrun.png "xrun")

 - **Fully compatible with `xcodebuild`**
 - **Designed to work with CI environment, like [Travis](http://travis-ci.org)**
 - **Human-friendly, colored output**
 - **Compatible with latest Xcode versions**

Table of Contents
-----------------

 - [Installation](#1)
 - [Basic examples](#2)
 - [Example Travis configuration](#3)
 - [Compatibility with xcodebuild](#4)
 - [Code Signing](#5)
 - [Failures](#6)
 - [Usage](#7)
 - [License](#8)

<a name="1"></a>
## Installation

xrun can be easily installed with [Homebrew](http://brew.sh):

    brew install --HEAD macmade/tap/xrun

<a name="2"></a>
## Basic examples

    xrun clean build
    
Cleans the build directory and builds the first target in the Xcode project in the directory from which xrun was started.

    xrun -project Foo.xcodeproj -scheme Bar analyze test
    
Analyses and tests the scheme `Bar` of the `Foo.xcodeproj` project.

<a name="3"></a>
## Example Travis configuration

```yml
language: objective-c
install:
- brew install macmade/tap/xrun
- xrun setup
script:
- xrun build analyse test 
```

<a name="4"></a>
## Compatibility with xcodebuild

xrun is fully compatible with `xcodebuild`, and can be used with the same command line options:

    xrun install DSTROOT=/ -alltargets

<a name="5"></a>
## Code-Signing

**xrun supports code-signing, even on CI environments, like [Travis](http://travis-ci.org)**.

When building locally, developer identities stored in your keychain will be used.  
But on a continuous integration system, your developer certificates need to be imported, so your project can be code-signed, and built successfully.

When run, xrun will look for an environment variable named `XRUN_CERT`.  
If it is defined, its data should contain a base-64 encoded **PKCS 12** file (.p12).

It will then create a keychain in its `setup` action, and import your developer identities from the `XRUN_CERT` environment variable.  
You'll then be able to use code-signing, even for continuous integration builds.

On macOS, you can export your developer identity from the **Keychain.app** application, as a **PKCS 12** file.  
You can then get a base-64 encoded string from the file using the following command:

    openssl enc -base64 -in /path/to/p12/file

<a name="6"></a>
## Failures

**xrun allows a better control on failures compared to `xcodebuild`.**

When building a project, unless `-Werror` is specified, `xcodebuild` will exit successfully even if warnings were produced.

xrun can take an optional `-fail-warn` flag that will fail the build process if a warning is detected.

**The same applies for the static analyzer.**  
With `xcodebuild`, warnings from the static analyzer are not considered as errors, and the whole analysis phase, if enabled, will succeed even if it detected issues.

**This can be a huge issue, especially with continuous integration.**  
For this reason, xrun's `-fail-warn` flag also applies to static analysis.

<a name="7"></a>
## Usage

    Usage: xrun [-project <project>] [[-scheme <scheme>]...] [<action>]...
    
    Available actions:
    
        build                   Build the target in the build root (SYMROOT).
                                This is the default action, and is used if no
                                action is given.
        
        build-for-testing       Build the target and associated tests in the
                                build root (SYMROOT).
                                This will also produce an xctestrun file in the
                                build root.
                                This requires specifying a scheme.
        
        analyze                 Build and analyze a target or scheme from the
                                build root (SYMROOT).
                                This requires specifying a scheme.
        
        archive                 Archive a scheme from the build root (SYMROOT). 
                                This requires specifying a scheme.
        
        test                    Test a scheme from the build root (SYMROOT).
                                This requires specifying a scheme and optionally
                                a destination.
        
        test-without-building   Test compiled bundles. If a scheme is provided
                                with -scheme then the command finds bundles in
                                the build root (SRCROOT).
                                If an xctestrun file is provided with -xctestrun
                                then the command finds bundles at paths
                                specified in the xctestrun file.
        
        install-src             Copy the source of the project to the source
                                root (SRCROOT).
        
        install                 Build the target and install it into the
                                target's installation directory in the
                                distribution root (DSTROOT).
        
        clean                   Remove build products and intermediate files
                                from the build root (SYMROOT).
        
        setup                   Performs initial setup and install additional
                                dependancies.
    
    Options:
        
        -help                   Displays the command usage.
        -version                Displays the xrun version.
        -license                Displays the xrun license.
        -verbose                Enables verbose mode.
        -project                Specifies the Xcode project.
        -scheme                 Specifies the Xcode scheme.
                                This argument may be supplied multiple times.
        -no-prompt              Disables prompt hierarchy.
        -fail-warn              Fails when detecting warnings.
        -disable-colors         Disables the colored output.
        -disable-icons          Disables the status icons.

<a name="8"></a>
## License

xrun is released under the terms of the MIT license.

## Repository Infos

    Owner:          Jean-David Gadina - XS-Labs
    Web:            www.xs-labs.com
    Blog:           www.noxeos.com
    Twitter:        @macmade
    GitHub:         github.com/macmade
    LinkedIn:       ch.linkedin.com/in/macmade/
    StackOverflow:  stackoverflow.com/users/182676/macmade
