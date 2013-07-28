/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#pragma once

#ifdef WIN32
#pragma pack(push,1)
#endif

namespace stm32plus {
	namespace fat {


	/**
	 * @brief Fat12/16 specific part of the boot sector
	 */

		struct BootSector16 {

			/// Int 0x13 drive number (e.g. 0x80). This field supports MS-DOS bootstrap and is set to the INT 0x13 drive number of the media (0x00 for floppy disks, 0x80 for hard disks).
			uint8_t		BS_DrvNum;

			/// Reserved (used by Windows NT). Code that formats FAT volumes should always set this byte to 0.
			uint8_t   BS_Reserved1;

			/// Extended boot signature (0x29). This is a signature byte that indicates that the following three fields in the boot sector are present.
			uint8_t   BS_BootSig;

			/// Volume serial number. This field, together with BS_VolLab, supports volume tracking on removable media. These values allow FAT file system drivers to detect that the wrong disk is inserted in a removable drive. This ID is usually generated by simply combining the current date and time into a 32-bit value.
			uint32_t  BS_VolID;

			/// Volume label. This field matches the 11-byte volume label recorded in the root directory.
			char      BS_VolLab[11];

			/// One of the strings "FAT12   ", "FAT16   ", or "FAT     ".
			char   		BS_FilSysType[8];
#ifdef WIN32
    };
#else
  } __attribute__ ((packed));
#endif
	}
}

#ifdef WIN32
#pragma pack(pop)
#endif