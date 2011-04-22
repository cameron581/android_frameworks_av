/*
 * Copyright (C) 2004-2011 NXP Software
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/**
 ******************************************************************************
 * @file    M4ChannelCoverter.c
 * @brief
 * @note
 ******************************************************************************
 */

void MonoTo2I_16( const short *src,
                        short *dst,
                        short n)
{
    short ii;
    src += n-1;
    dst += (n*2)-1;

    for (ii = n; ii != 0; ii--){
        *dst-- = *src;
        *dst-- = *src--;
    }

    return;
}

void From2iToMono_16( const short *src,
                            short *dst,
                            short n)
{
    short ii;
    long Temp;
    for (ii = n; ii != 0; ii--) {
        Temp = (long)*(src++);
        Temp += (long)*(src++);
        *(dst++) = (short)(Temp >>1);
    }

    return;
}

