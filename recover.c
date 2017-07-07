#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    if(argc!=2)
    {
    fprintf(stderr,"Usage: ./recover");
    return 1;
    }
    
    // opening memory card file
    FILE* inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(inptr,"Error: unable to open file  %s.\n", argv[1]);
        return 2;
    }
    
    FILE* outptr = NULL;
    
    // creating 512 byte buffer array
    typedef uint8_t  BYTE;
    BYTE buffer[512];
    
    // creating array for first four bytes of the buffer
    BYTE firstfour[4];
    
    // the first 4 bytes of a jpeg file (i.e. jpeg signature)
    // the last four bits can range from 0-f and are hardcoded as zeros here
    BYTE jpgsig[4] = {0xff, 0xd8, 0xff, 0xe0};
    
    // keep track of jpeg numbers for jpeg filenames
    int jpgnumber = 0;
    char jpgfilename[8];
    int i;
    
    // read a buffer from card.raw until EOF
    while (fread(&buffer, sizeof(buffer), 1, inptr) > 0)
    {
        // loading first three bytes of the buffer into firstfour
	for ( i = 0; i < 4; i++)
	{
	    firstfour[i] = buffer[i];
	}
	
	// hard code zeros into last four bits of fourth byte in firstfour
	firstfour[3] = (firstfour[3] >> 4) << 4;
	
        // if jpeg signature is found
        if (memcmp(firstfour, jpgsig, sizeof(jpgsig)) == 0)
        {
            // a jpeg is not yet open 
            if (outptr == NULL)
            {
                sprintf(jpgfilename, "%03d.jpg", jpgnumber);
                outptr = fopen(jpgfilename, "a");
                fwrite(&buffer, sizeof(buffer), 1, outptr);
            }
            
            // a jpeg is already open
            else
            {
                fclose(outptr);
                jpgnumber++;
                sprintf(jpgfilename, "%03d.jpg", jpgnumber);
                outptr = fopen(jpgfilename, "a");
                fwrite(&buffer, sizeof(buffer), 1, outptr);
            }
        }
        
        else
        {
            // a jpeg is already open
            if (outptr != NULL)
            {
                fwrite(&buffer, sizeof(buffer), 1, outptr);
            }
        }
    }
    
    // close files and exit 
    fclose(inptr);
    fclose(outptr);
    return 0;
}