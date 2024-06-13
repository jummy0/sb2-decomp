#pragma once

/* To maintain compatibility with the modern Win32 API, some overlapping
 * function names need to be cleared up.  This file is fabricated,
 * and not present in the original Speedy Blupi source code.
 */

#ifdef GetObjectA
	#undef GetObject
#endif