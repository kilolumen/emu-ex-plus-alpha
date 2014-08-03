#pragma once

/*  This file is part of Imagine.

	Imagine is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Imagine is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Imagine.  If not, see <http://www.gnu.org/licenses/> */

#include <imagine/fs/Fs.hh>

#if defined CONFIG_FS_POSIX
#include <imagine/fs/FsPosix.hh>
#define FsSys FsPosix
#elif defined CONFIG_FS_WIN32
#include <imagine/fs/FsWin32.hh>
#define FsSys FsWin32
#elif defined CONFIG_FS_PS3
#include <imagine/fs/FsPs3.hh>
#define FsSys FsPs3
#endif

static FsSys::PathString makeFSPathStringPrintf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));
static FsSys::PathString makeFSPathStringPrintf(const char *format, ...)
{
	FsSys::PathString path{};
	va_list args;
	va_start(args, format);
	int ret = vsnprintf(path.data(), sizeof(path), format, args);
	assert(ret >= 0);
	va_end(args);
	return path;
}