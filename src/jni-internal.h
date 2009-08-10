/*
 * Copyright (C) 2009 Robert Lougher <rob@lougher.org.uk>.
 *
 * This file is part of JamVM.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#define REF_MASK         0x3
#define GLOBAL_REF       0x2
#define WEAK_GLOBAL_REF  0x1
#define CLEARED_WEAK_REF 0x0

#define REF_TO_OBJ_WEAK_NULL_CHECK(ref) ({           \
    Object *_obj = REF_TO_OBJ(ref);                  \
    if(REF_TYPE(ref) == WEAK_GLOBAL_REF)             \
        _obj = isPlaceholderObj(_obj) ? NULL : _obj; \
    _obj;                                            \
})

#define REF_TYPE(ref)   (((uintptr_t)(ref))&REF_MASK)
#define REF_TO_OBJ(ref) ((Object*)(((uintptr_t)(ref))&~REF_MASK))
#define OBJ_TO_REF(ref, ref_type) ((jobject)(((uintptr_t)(ref))|ref_type))
