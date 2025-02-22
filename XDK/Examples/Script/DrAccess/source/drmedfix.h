/****************************************************************************
 *
 * If you write the mediaData handle for #moaComposite passed back by 
 * IMoaDrCastMem::GetMedia() to a file, you will find at the start of the 
 * byte stream in Director 5:
 *  - 8 bytes of internal info about the media handle that appears to be irrelevant
 *  - two 32-bit numbers about the media handle that are _not_ byte swapped; 
 *    these are related to the handle size.
 *  - a 16-bit header size that is _not_ byte swapped
 *  - a 32-bit version number that is _not_ byte-swapped
 *  - a 32-bit internal cast member type number that is _not_ byte-swapped
 *  - a 32-bit properties length number that is _not_ byte-swapped 
 * This comes to 30 bytes (0x001e), which is the header size value.
 ****************************************************************************/ 

void DrFixMediaHeader(const char * pMediaData);
