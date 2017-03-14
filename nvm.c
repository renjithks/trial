/** Property entry definition struct
 * 
 */
typedef struct
{
	unsigned long tag;            /**< Tag */
	unsigned int  len;            /**< Number of bytes */
	unsigned long data;           /**< Byte string */
	unsigned int  max_len;        /**< Max length */
}
hal_property_entry;


/** Term Table structure definition
 * 
 */
typedef struct
{
	hal_property_entry entry[HAL_PROPERTY_MAX_TERM_TABLE_ENTRIES]; /**<array for term table entries */
}
hal_property_term_table;

/** App Table structure definition
 * 
 */
typedef struct
{
	hal_property_entry entry[HAL_PROPERTY_MAX_APP_TABLE_ENTRIES]; /**<array for app table entries */
}
hal_property_app_table;

/** DRL Table structure definition
 * 
 */
typedef struct
{
	hal_property_entry entry[HAL_PROPERTY_MAX_DRL_TABLE_ENTRIES]; /**<array for drl table entries */
}
hal_property_drl_table;

/** Language Table structure definition
 * 
 */
typedef struct
{
	hal_property_entry entry[HAL_PROPERTY_MAX_LANG_TABLE_ENTRIES]; /**<array for lang table entries */
} hal_property_lang_table;

/** Cakey Table structure definition
 * 
 */
typedef struct
{
	hal_property_entry entry[HAL_PROPERTY_MAX_CAKEY_TABLE_ENTRIES]; /**<array for cakey table entries */
} hal_property_cakey_table;


/** Contains an offset to a specific table 
 * 
 */
typedef struct
{
	unsigned long offset; /**<offset */
}
hal_property_table_offset;


/** Contains a set of tables offsets
 * 
 */
typedef struct
{
	hal_property_table_offset offsets[HAL_PROPERTY_MAX_DATABASE_TABLES]; /**<offsets */
}
hal_property_base;


/** global variable used across files */
unsigned short _hal_prop_config_item = 0;


/** @}*/

/* 
 * A const variable cannot be used to define a table size
 * MAX_HAL_PROP_CONFIGS is used externally in other files
 */
#ifdef _FLASH_BUILD
/* 
 * NOTE: in case of a flash build, databases go into the m_hal_prop section (see inl files) 
 * warning: GCC issues a warning and otherwise ignores the section attribute in uninitialized variable declarations
 */
#ifdef __DEVEL_BUILD_
/** ATTRIB */
#	define ATTRIB __attribute__ ((section (".hal_nvm_prop")))
#endif
// Device Database
#ifdef __DEVEL_BUILD_
/** DB ATTRIB */
#	define DB_ATTRIB __attribute__ ((section (".hal_nvm_db")))
#endif
/** LANG ATTRIB */
#	define LANG_ATTRIB __attribute__ ((section (".hal_nvm_lang")))
/** SIG ATTRIB */
#	define SIG_ATTRIB __attribute__ ((section (".hal_sig_db")))

/** LOCAL MAX HAL PROP CONFIGS*/
#	define LOCAL_MAX_HAL_PROP_CONFIGS 1
# else
#	define ATTRIB
#	define LANG_ATTRIB
#	define LOCAL_MAX_HAL_PROP_CONFIGS 1
#endif

/**MAX HAL PROP CONFIGS*/
const  unsigned short MAX_HAL_PROP_CONFIGS = LOCAL_MAX_HAL_PROP_CONFIGS;
/**terminal settings table HAL Property handle*/
static HAL_PROPERTY_HANDLE terminal_settings_table[LOCAL_MAX_HAL_PROP_CONFIGS] = {0};


// language database
#include "language_database.inl"

#ifdef __DEVEL_BUILD_
// terminal database
#include "TerminalSettings_database_emv_ct_conf01.inl"
#else
#define TERMINAL_DB_ADRESS 0x000EC000
#endif

// Device Database
#ifdef __DEVEL_BUILD_
#include "DeviceSettings_Database_Devel.inl"
#else
#define BOOTLOADER_DB_ADRESS 0x000F9000
#endif

_flash_const_ unsigned char digital_sinature[256] SIG_ATTRIB = 
{ 
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

/**
 * @brief Write in Non-Volatile Memory interface.
 */
int hal_nvm_write( HAL_NVM_HANDLE handle, unsigned char *dst, 
							unsigned char *src, unsigned int length )	
{
	// Calculating the sector address to write
	unsigned int sector_address = ( ( ( unsigned int ) dst >> 12 ) << 12 );
	// Calculating the starting address in sector to write
	unsigned int inLocation = (unsigned int)dst-sector_address;
	// Buffer to backup the sector before erase 
	unsigned char backupBuffer[FLASH_SECTOR_SIZE];
	unsigned int dLength = 0;
	int rv = HAL_NVM_E_SUCCESS;
	
	if ( null == handle ) 
	{
		rv = HAL_NVM_E_ERROR;
		goto out;
	}
	
	do {
		// Check for buffer overflow and get the buffer length to copy
		dLength = ( length > ( FLASH_SECTOR_SIZE - inLocation ) ) ? 
					( FLASH_SECTOR_SIZE - inLocation ) : length;
		// backup the entire sector before erase
		memset( backupBuffer, 0xFF, FLASH_SECTOR_SIZE );
		memcpy( backupBuffer, ( unsigned int* )sector_address, FLASH_SECTOR_SIZE ); 
		// copy data to be written to sector buffer
		memcpy( ( backupBuffer + inLocation ), src, dLength );
		
		// Erase the entire sector before flashing the data
		rv = flash_sectorErase( ( unsigned int* )sector_address );
		if( E_FLASH_SUCCESS != rv ) 
		{
			rv = HAL_NVM_E_ERROR;
			goto out;
		}
		
		// TODO: chk return code
		rv = flash_sectorWrite( ( unsigned int* )sector_address, 
						( unsigned int* )backupBuffer, FLASH_SECTOR_SIZE );
		if( E_FLASH_SUCCESS != rv ) 
		{
			rv = HAL_NVM_E_ERROR;
			goto out;
		}
		
		// Getting the number of bytes left
		length -= dLength;
		// Calculate the next sector to write
		sector_address += FLASH_SECTOR_SIZE;
		// Pointing to the starting of new sector
		inLocation = 0;
		// Pointing toi the data left in the src
		src = src + dLength;
	
	}while( length );
	
out:
 	EnableInterrupts;
    return rv;
}


/**
 * @brief Initializes the Property Configuration Database interface.
 */
int hal_property_init( void )
{
	int rv;

	rv = hal_nvm_init();
	if (HAL_NVM_E_SUCCESS != rv)
		return HAL_PROPERTY_E_ERROR;

#ifdef __DEVEL_BUILD_
	terminal_settings_table[0]  = &emv_ct_hal_property_database;
#else
	terminal_settings_table[0] = (HAL_PROPERTY_HANDLE)TERMINAL_DB_ADRESS;
#endif

	return HAL_PROPERTY_E_SUCCESS;
}


/**
 * @brief Shutdowns the Property Configuration Database interface.
 */
int hal_property_terminate( void )
{
	int rv;

	rv = hal_nvm_terminate();
	if ( HAL_NVM_E_SUCCESS != rv )
		return HAL_PROPERTY_E_ERROR;

	return HAL_PROPERTY_E_SUCCESS;
}


/**
 * @brief Open a Property Configuration Database interface.
 */
int hal_property_open( void *params, HAL_PROPERTY_HANDLE *handle )
{
	unsigned char *kernel_id = (unsigned char *)params;

	switch ( *kernel_id )
	{
	case EMV_KERNEL_ID_EMVCT: // EMV Contact
		*handle = (HAL_PROPERTY_HANDLE)terminal_settings_table[_hal_prop_config_item];
		break;
	case 0x6C:  // Language database
		*handle = (HAL_PROPERTY_HANDLE)&lang_hal_property_database;
		break;

	case DB_BL_ID:
#ifndef __DEVEL_BUILD_
		*handle = (HAL_PROPERTY_HANDLE)BOOTLOADER_DB_ADRESS;
#else
		*handle = (HAL_PROPERTY_HANDLE)&DBDEVEL_hal_property_database;
#endif
		break;

	default:
		return -HAL_PROPERTY_E_INVAL;
	}

	return HAL_PROPERTY_E_SUCCESS;
}


/**
 * @brief Closes a Property Configuration Database interface.
 */
int hal_property_close( HAL_PROPERTY_HANDLE handle )
{
	int rv = HAL_PROPERTY_E_SUCCESS;

	// Release resources
	if (handle == null)
	{
		rv = -HAL_PROPERTY_E_INVAL;
	}

	return rv;
}

/**
 * @brief Retrieves the max allocated value of the specified byte array property.
 */
int hal_property_get_max_bytes( HAL_PROPERTY_HANDLE handle, int category,
		unsigned long id, unsigned char **value,
		unsigned int *length )
{
	int                rv = -HAL_PROPERTY_E_NOT_FOUND;
	hal_property_base  *base = (hal_property_base *)handle;
	hal_property_entry *entry = NULL;

	if (NULL != value)
		*value = NULL;
	if (NULL != length)
		*length = 0;

	if (handle == null)
	{
		rv = -HAL_PROPERTY_E_INVAL;
		goto out;
	}

	if (handle != &lang_hal_property_database)
	{
		/* If the table does not exist, go out */
		if (base->offsets[category].offset == 0)
		{
			goto out;
		}

		entry = (hal_property_entry *)((unsigned long)base +
				base->offsets[category].offset);

		for (; entry->tag != NULL; entry++)
		{
			if (entry->tag == id)
			{
				if (NULL != value)
					*value  = (unsigned char *)((unsigned long)base + entry->data);

				if (NULL != length)
					*length = entry->max_len;
				// #TODO hard coding length to fix issue in the inl - remove this after fixing the issue int inl
				if( EMV_APPL_DDOL == id ){*length = 0x0B;}

				rv = HAL_PROPERTY_E_SUCCESS;
				break;
			}
		}
	}

	out:
	return rv;
}

/**
 * @brief Retrieves the value of the specified byte array property.
 */
int hal_property_get_bytes( HAL_PROPERTY_HANDLE handle, int category,
		unsigned long id, unsigned char **value,
		unsigned int *length )
{
	int                rv = -HAL_PROPERTY_E_NOT_FOUND;
	hal_property_base  *base = (hal_property_base *)handle;
	hal_property_entry *entry = NULL;

	if (NULL != value)
		*value = NULL;
	if (NULL != length)
		*length = 0;

	if (handle == null)
	{
		rv = -HAL_PROPERTY_E_INVAL;
		goto out;
	}

	if (handle != &lang_hal_property_database)
	{
		/* If the table does not exist, go out */
		if (base->offsets[category].offset == 0)
		{
			goto out;
		}

		entry = (hal_property_entry *)((unsigned long)base +
				base->offsets[category].offset);

		for (; entry->tag != NULL; entry++)
		{
			if (entry->tag == id)
			{
				if (NULL != value)
					*value  = (unsigned char *)((unsigned long)base + entry->data);

				if (NULL != length)
					*length = entry->len;

				rv = HAL_PROPERTY_E_SUCCESS;
				break;
			}
		}
	}
	else
	{
		// Language database
		switch (category)
		{
		case TERM_PROPERTY:
			break;
		case 0x656E:    // English
			id |= 0xCB00; // make it a tag that match the inl's ones
			category = LANG_PROPERTY;
			break;

		case 0x6672:    // French
			id |= 0xCB00; // make it a tag that match the inl's ones
			category = LANG_PROPERTY + 1;
			break;

		case 0x6465:    // German
			id |= 0xCB00; // make it a tag that match the inl's ones
			category = LANG_PROPERTY + 2;
			break;

		case 0x6974:    // Italian
			id |= 0xCB00; // make it a tag that match the inl's ones
			category = LANG_PROPERTY + 3;
			break;

		default:
			goto out;
		}

		entry = (hal_property_entry *)((unsigned long)base +
				base->offsets[category].offset);

		for (; entry->tag != NULL; entry++)
		{
			if (entry->tag == id)
			{
				if (category != TERM_PROPERTY)
				{
					unsigned long *address;
					address = (unsigned long *)((unsigned long)base +
							entry->data);
					*value = (unsigned char *)(address);
				}
				else
				{
					*value  = (unsigned char *)((unsigned long)base +
							entry->data);
				}
				*length = entry->len;
				rv = HAL_PROPERTY_E_SUCCESS;
				break;
			}
		}
	}

	out:
	return rv;
}

/**
 * @brief Retrieves the TAG entry bytes for the specified byte array property.
 */
int hal_property_get_entry_bytes( HAL_PROPERTY_HANDLE handle, int category,
		unsigned long id, HAL_PROPERTY_ENTRY **ret_entry )
{
	int rv = -HAL_PROPERTY_E_NOT_FOUND;
	hal_property_base  *base = (hal_property_base *)handle;
	hal_property_entry *entry = NULL;

	if (handle == null)
	{
		rv = -HAL_PROPERTY_E_INVAL;
		goto out;
	}

	if (handle != &lang_hal_property_database)
	{
		/* If the table does not exist, go out */
		if (base->offsets[category].offset == 0)
		{
			goto out;
		}

		entry = (hal_property_entry *)((unsigned long)base +
				base->offsets[category].offset);

		for (; entry->tag != NULL; entry++)
		{
			if (entry->tag == id)
			{
				*ret_entry = ( HAL_PROPERTY_ENTRY )entry;
				rv = HAL_PROPERTY_E_SUCCESS;
				break;
			}
		}
	}

	out:
	return rv;
}

/**
 * @brief Retrieves the value of the specified "Integer" property.
 */
int hal_property_get_integer(HAL_PROPERTY_HANDLE handle, int category,
		unsigned long id, unsigned int *value)
{
	int            rv;
	unsigned int   length = 0;
	unsigned int   i;
	unsigned char *tmpval = 0;

	if (handle == null)
	{
		rv = HAL_PROPERTY_E_INVAL;
		goto out;
	}

	*value = 0;
	rv = hal_property_get_bytes(handle, category, id, &tmpval, &length);
	if ((rv != HAL_PROPERTY_E_SUCCESS) || (length == 0))
	{
		goto out;
	}
	/* WARNING: the retrieved value can be an unsigned char, short, or int */
	for (i = length; i > 0; --i)
	{
		*value += tmpval[i-1] << ( (length-i) << 3 /*x8*/ );
	}

	out:
	return rv;
}

/**
 * @brief Stores the value of the specified byte array property.
 */
int hal_property_set_bytes( HAL_PROPERTY_HANDLE handle, int category,
		unsigned long id, unsigned char *value,
		uint32_t length )
{

	int                rv = HAL_PROPERTY_E_SUCCESS;
	uint32_t       ulength = length;
	hal_property_base  *base = (hal_property_base *)handle;
	hal_property_entry *entry;

	if (handle == null) {
		rv = HAL_PROPERTY_E_INVAL;
		goto out;
	}

	entry = ( hal_property_entry * )( ( unsigned long )base \
			+ base->offsets[category].offset );

	for ( ; entry->tag != 0; entry++ ) {
		if (entry->tag == id) {

			if (entry->max_len < ulength) {
				ulength = entry->max_len;
			}

			rv = hal_nvm_write(handle, ( unsigned char * )( &( entry->len ) ),
					( unsigned char * )&ulength,sizeof( int ) );

			if (rv != HAL_NVM_E_SUCCESS) {
				break;
			}

			rv = hal_nvm_write(handle, (unsigned char *)((unsigned long)base \
					+ entry->data), value, ulength);

			if (rv != HAL_NVM_E_SUCCESS) {
				break;
			}	
		}
	}

	out:
	return rv;
}

/**
 * @brief Gets the plain text data from flash 
 */
int hal_property_get_data( unsigned char* tagData, unsigned long key_id ) 
{
	unsigned char *value = NULL;
	unsigned int  length = 0;
	short rv;
	HAL_PROPERTY_HANDLE handle;

	// Open a Property Configuration Database interface.				
	hal_property_open( "\x8C", &handle );
	// Retrieve KEY from  of database table
	rv = hal_property_get_bytes( handle, DB_PROPERTY, key_id, &value, &length );
	if ( rv != HAL_PROPERTY_E_SUCCESS )
	{
		goto out;
	}
	// Get the value to the buffer
	memcpy( tagData, value, length );

	out:
	hal_property_close( handle );
	return rv;	
}

/**
 * @brief Stores the Data in to the flash in plain text
 */
short hal_property_flash_data( char* tagData, unsigned long data_id )
{
	int rv;
	HAL_PROPERTY_HANDLE    handle;
	unsigned char *value = NULL;
	unsigned int  length = 0;

	// Open a Property Configuration Database interface.				
	rv = hal_property_open( "\x8C", &handle );
	if( HAL_PROPERTY_E_SUCCESS != rv ) 
	{
		goto out;
	}

	// Retrieve MSR IPEK VALUE  of database table
	rv = hal_property_get_bytes(handle, DB_PROPERTY, data_id, &value, &length);
	if (rv != HAL_PROPERTY_E_SUCCESS)
	{
		goto out;
	}
	// flash device serial number to database table
	rv = hal_property_set_bytes( handle, DB_PROPERTY, data_id, 
			( unsigned char* )tagData, length );
	if ( rv != HAL_PROPERTY_E_SUCCESS )
	{
		goto out;
	}

	out:
	return rv;
}
