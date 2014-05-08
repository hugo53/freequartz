/*
 * Copyright (c) 2007-2009 by Apple Inc.. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

/*
    File:       AvailabilityInternal.h
 
    Contains:   implementation details of __OSX_AVAILABLE_* macros from <Availability.h>

*/
#ifndef __AVAILABILITY_INTERNAL__
#define __AVAILABILITY_INTERNAL__


// if we want to support some compiler that does not support these
// attributes, we can test for the compiler version before defining these
#define __AVAILABILITY_INTERNAL_DEPRECATED         __attribute__((deprecated))
#define __AVAILABILITY_INTERNAL_UNAVAILABLE        __attribute__((unavailable))
#define __AVAILABILITY_INTERNAL_WEAK_IMPORT        __attribute__((weak_import))
#define __AVAILABILITY_INTERNAL_REGULAR            


#ifndef __IPHONE_OS_VERSION_MIN_REQUIRED
    #ifdef __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__
        // compiler sets __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ when -miphoneos-version-min is used
        #define __IPHONE_OS_VERSION_MIN_REQUIRED __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__
    #endif
#endif


#ifdef __IPHONE_OS_VERSION_MIN_REQUIRED
    // make sure a default max version is set
    #ifndef __IPHONE_OS_VERSION_MAX_ALLOWED
        #define __IPHONE_OS_VERSION_MAX_ALLOWED     __IPHONE_3_1
    #endif
    // make sure a valid min is set
    #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_0
        #undef __IPHONE_OS_VERSION_MIN_REQUIRED
        #define __IPHONE_OS_VERSION_MIN_REQUIRED    __IPHONE_2_0 
    #endif
    
    // set up internal macros (up to 2.0)
     #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_2_0
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0          __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_0
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0          __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0          __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_NA     __AVAILABILITY_INTERNAL__IPHONE_2_0
    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_0    __AVAILABILITY_INTERNAL_DEPRECATED
    // set up internal macros (up to 2.1)
    #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_2_1
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1                __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1                __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1                __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_NA     __AVAILABILITY_INTERNAL__IPHONE_2_1
    #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_1    __AVAILABILITY_INTERNAL_REGULAR  
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_1    __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_1    __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_1    __AVAILABILITY_INTERNAL_DEPRECATED
    #endif
    // set up internal macros (up to 2.2)
    #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_2_2
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2                __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2                __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2                __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_NA     __AVAILABILITY_INTERNAL__IPHONE_2_2
    #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_2    __AVAILABILITY_INTERNAL_REGULAR  
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_2    __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_2_2    __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_2    __AVAILABILITY_INTERNAL_REGULAR    
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_2    __AVAILABILITY_INTERNAL_REGULAR   
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_2_2    __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_2    __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_2    __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_2_2    __AVAILABILITY_INTERNAL_DEPRECATED
    #endif
    // set up internal macros (up to 3.0)
    #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_3_0
        #define __AVAILABILITY_INTERNAL__IPHONE_3_0                __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
        #define __AVAILABILITY_INTERNAL__IPHONE_3_0                __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__IPHONE_3_0                __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_NA     __AVAILABILITY_INTERNAL__IPHONE_3_0
    #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_REGULAR    
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_REGULAR   
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_REGULAR   
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_REGULAR   
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_REGULAR   
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_REGULAR   
        #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0    __AVAILABILITY_INTERNAL_DEPRECATED
    #endif
    // set up internal macros (up to 3.1)
    #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_3_1
        #define __AVAILABILITY_INTERNAL__IPHONE_3_1                __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
        #define __AVAILABILITY_INTERNAL__IPHONE_3_1                __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__IPHONE_3_1                __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_NA     __AVAILABILITY_INTERNAL__IPHONE_3_1
    #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_REGULAR    
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_WEAK_IMPORT
		#define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_WEAK_IMPORT
   #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_REGULAR   
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_REGULAR   
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_REGULAR   
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_REGULAR   
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_REGULAR   
        #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_REGULAR   
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_REGULAR   
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_REGULAR   
        #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_REGULAR
        #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1    __AVAILABILITY_INTERNAL_DEPRECATED
    #endif
    // set up internal macros (n/a)
    #define __AVAILABILITY_INTERNAL__IPHONE_NA                     __AVAILABILITY_INTERNAL_UNAVAILABLE 
    #define __AVAILABILITY_INTERNAL__IPHONE_NA_DEP__IPHONE_NA      __AVAILABILITY_INTERNAL_UNAVAILABLE
    
#elif defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)
    // compiler for Mac OS X sets __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
    #define __MAC_OS_X_VERSION_MIN_REQUIRED __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
    // make sure a default max version is set
    #ifndef __MAC_OS_X_VERSION_MAX_ALLOWED
        #define __MAC_OS_X_VERSION_MAX_ALLOWED __MAC_10_6
    #endif

    // set up internal macros
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_6
        #define __AVAILABILITY_INTERNAL__MAC_10_6        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_6
        #define __AVAILABILITY_INTERNAL__MAC_10_6        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else    
        #define __AVAILABILITY_INTERNAL__MAC_10_6        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_5
        #define __AVAILABILITY_INTERNAL__MAC_10_5        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_5
        #define __AVAILABILITY_INTERNAL__MAC_10_5        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_5        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_4
        #define __AVAILABILITY_INTERNAL__MAC_10_4        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_4
        #define __AVAILABILITY_INTERNAL__MAC_10_4        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_4        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_3        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_3        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_3        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_2        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_2        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else   
        #define __AVAILABILITY_INTERNAL__MAC_10_2        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_1        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_1        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_1        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_0        __AVAILABILITY_INTERNAL_UNAVAILABLE
    #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_0        __AVAILABILITY_INTERNAL_WEAK_IMPORT
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0        __AVAILABILITY_INTERNAL_REGULAR
    #endif
    #define __AVAILABILITY_INTERNAL__MAC_NA             __AVAILABILITY_INTERNAL_UNAVAILABLE
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1        __AVAILABILITY_INTERNAL__MAC_10_0
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2        __AVAILABILITY_INTERNAL__MAC_10_1
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3        __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3        __AVAILABILITY_INTERNAL__MAC_10_2
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_4
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4        __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4        __AVAILABILITY_INTERNAL__MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4        __AVAILABILITY_INTERNAL__MAC_10_3
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_5
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5        __AVAILABILITY_INTERNAL__MAC_10_4
    #endif
    #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_6
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6        __AVAILABILITY_INTERNAL_DEPRECATED
    #else
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_4
        #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6        __AVAILABILITY_INTERNAL__MAC_10_5
    #endif
    #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_0
    #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_1
    #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_2
    #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_3
    #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_4
    #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_5
    #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_6
    #define __AVAILABILITY_INTERNAL__MAC_NA_DEP__MAC_NA               __AVAILABILITY_INTERNAL_UNAVAILABLE

#endif

#endif // __AVAILABILITY_INTERNAL__
