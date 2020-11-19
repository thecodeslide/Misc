/****************************************************************************
 * dictionary.c
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

// create hash table and initialise all values to NULL
node* root;

unsigned int count = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO // done

    node* cursor = root;
    // iterate through the word
    for (uint16_t j = 0, w = 0, k = strlen(word); j < k; j++)
    {
        // check for apostrophe
        if (word[j] == '\'')
            w = 26;
        else w = hashme(tolower(word[j]));
        
        // iterate through the trie
        if (cursor != NULL)
        {   
            // letter does not exist
            if (cursor->children[w] == NULL)
                return false;
            // move to next letter    
            cursor = cursor->children[w];
            
            if ((cursor->is_word) &&  j == k - 1)
                return true;
        }
    }    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO // done
    // open file
    FILE* infile = fopen(dictionary, "r");
 	int index = 0, hIndex = 0;
 	
 	if (infile)
 	{	
		// malloc and initialize root node array elements to NULLs	
     	root = (node*) calloc(1, sizeof(node));
     	node* current = root;
     	
     	// assume only lower cap words and apostrophes will be in dictionary
	    for (int c = fgetc(infile); c != EOF; c = fgetc(infile))
	    {
		    if (isalpha(c) || (c == '\'' && index > 0))
            {
                // get index of array for element
                if (c == '\'') // dec 39 
                    hIndex = 26; 
                else hIndex = hashme(c); // or c - a
                index++;
                // inserting elements into node array
                if (current->children[hIndex] == NULL)
                {	
                    current->children[hIndex] = (node*) calloc(1, sizeof(node));;
                    current = current->children[hIndex];
                }
                else if (index > LENGTH)
                {
                    // consume remainder of alphabetical string
                    while ((c = fgetc(infile)) != EOF && isalpha(c));
					// prepare for new word
                    index = 0;
                }
				// letter already exists so we move on
                else
                    current = current->children[hIndex];
            }
            // we must have found a whole word
            else if (index > 0)
            {
                // terminate current word
                if (!(current->is_word))
                    current->is_word = true;
                
                current = root;
                // update counter
                count++;
                index = 0;
        	}
	    }
	    if (ferror(infile))
        {   
        	puts("I/O error when reading");
            return false;
        }
        if (feof(infile))
        {    
        	fclose(infile);
		    return true;
	    }  
    }
    perror("File opening failed");
	return false;
}

/**
 * Returns hash.
 */
uint16_t hashme(uint16_t c)
{
       return (c % 26); // 0 - 25 or c - a
}

/*uint32_t hashme(const char* word) */
/*{*/
/*	uint32_t hash = (toupper(word[0])-'A');*/
/*    return hash;*/
/*} */

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO // done
    if (count > 0)
    	return count;
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO // DONE
    // recursive function through trie to free nodes
    return (unloadme(root));
    return false;
}

/**
 * recursive loop to unload dictionary from memory.  Returns true if successful else false.
 */
bool unloadme(node* cursor)
{
    for (uint16_t i = 0; i < 27; i++)
        if (cursor->children[i] != NULL)
        {    
            unloadme(cursor->children[i]);
        }
       
    free(cursor);
    cursor = NULL;
    return (cursor == NULL);    
}