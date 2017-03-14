
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
