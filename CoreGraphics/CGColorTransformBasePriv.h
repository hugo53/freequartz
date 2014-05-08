/* Copyright 2010 Smartmobili SARL
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef CGCOLORTRANSFORMBASEPRIV_H_
#define CGCOLORTRANSFORMBASEPRIV_H_

#include <CoreFoundation/CFRuntime.h>
#include <CoreGraphics/CGColorSpace.h>
#include <CoreGraphics/CGPattern.h>

#include "CGMacros.h"

CF_EXTERN_C_BEGIN

typedef struct CGColorTransformBase {
	CFRuntimeBase obj;

} CGColorTransformBase, *CGColorTransformBaseRef;

CG_EXTERN void colortransformBaseFinalize(CFTypeRef ctf);
CG_EXTERN CGColorTransformBaseRef CGColorTransformBaseRetain(CGColorTransformBaseRef colorTransform);
CG_EXTERN void CGColorTransformBaseRelease(CGColorTransformBaseRef colorTransform);
CG_EXTERN CFTypeID CGColorTransformBaseGetTypeID(void);


CF_EXTERN_C_END

#endif /* CGCOLORTRANSFORMBASEPRIV_H_ */


