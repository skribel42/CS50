#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: recover <file>\n");
        return 1;
    }

    // open the memory card ..
    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if(file==NULL){
        printf("Unable to open file. %s \n", filename);
        return 1;
    }

    FILE *img = NULL;
    uint8_t buffer[BLOCK_SIZE];
    char jpeg[8];
    int count = 0;

    // While theres still data left to read from the memory card..
    while (fread(buffer, 1, BLOCK_SIZE, file))
    {

        // create JPEGS from the data
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
            {
                if (count ==0)
                {
                    // create a new file to write data too
                    sprintf(jpeg, "%03i.jpg", count); // create filename string using value stored in count
                    img = fopen(jpeg, "w"); // opens the new file
                    fwrite(buffer, 1, BLOCK_SIZE, img);
                    count++;
                 } else if (count > 0)
                 {
                    fclose(img);
                    sprintf(jpeg, "%03i.jpg", count);
                    img = fopen(jpeg, "w");
                    fwrite(buffer, 1, BLOCK_SIZE, img);
                    count++;
                 }

            } else if(count > 0)
            {
                fwrite(buffer, 1, BLOCK_SIZE, img);
            }

    }


    // close the file
    fclose(file);
    if (img != NULL)
    {
        fclose(img);
    }
}