#include <string.h>
#include "Linked_list.h"
#include <iostream>

using namespace std;

//struct for each element - has key and value
template<typename Tkey, typename Tvalue> struct elem_info {
    Tkey key;
    Tvalue value; };

//implementation of Hashtable using LinkedList
template<typename Tkey, typename Tvalue> class Hashtable {
    private:
    //we have a list for each key! (an array of lists)
        LinkedList<struct elem_info<Tkey, Tvalue> > *H;
        int HMAX;
        //pointer to a hash function, of a certain type
        int (*hash)(Tkey);
        // 
        int *bucket_sizes;

        public:
            Hashtable(int hmax, int (*h) (Tkey)) {
	                HMAX = hmax;
	                hash = h;
	                H = new LinkedList<struct elem_info<Tkey,Tvalue> > [HMAX];
                    // 
                    bucket_sizes=new int[HMAX];
                    for(int i=0;i<HMAX;i++)
                        bucket_sizes[i]=0;
                }

			//add the pair (key, value)
			void put(Tkey key, Tvalue value)
			{
            	struct list_elem<struct elem_info<Tkey, Tvalue> > *p;
            	struct elem_info<Tkey, Tvalue> info;

            	//transform using the hash function
            	int hkey = hash(key);
				//first element of the list H[hkey]
            	p = H[hkey].pfirst;

            	while (p != NULL)
                {
					//if we find an element of this key, we will replace it  
	                if (p->info.key == key)
	                    break;
                    p = p->next;
                }

                if (p != NULL) //element which already has a key
                    p->info.value = value;
                else //element which does not have a key
                {
                    info.key = key;
                    info.value = value;
                    H[hkey].addLast(info);
                }
            }


            void put2(Tkey key, Tvalue value) {
                struct list_elem<struct elem_info<Tkey, Tvalue> > *p;
                struct elem_info<Tkey, Tvalue> info;

                // Transform key using the hash function
                int hkey = hash(key);

                // First element of the list H[hkey]
                p = H[hkey].pfirst;

                while (p != NULL) {
                    // If we find an element with this key, we will replace its value
                    if (p->info.key == key)
                        break;
                    p = p->next;
                }

                if (p != NULL) { // Element already exists with this key
                    p->info.value = value;
                } else { // Element doesn't exist with this key
                    info.key = key;
                    info.value = value;

                    // Find the next available slot
                    int bucket = hkey;
                    while (bucket_sizes[bucket] >= 3) {
                        bucket = (bucket + 1) % HMAX; // Move to the next bucket
                        if (bucket == hkey) {
                            // If we loop back to the original bucket, the hashtable is full
                            cerr << "Error: Hashtable is full." << endl;
                            return;
                        }
                    }

                    // Add the element to the next available slot
                    H[bucket].addLast(info);
                    ++bucket_sizes[bucket];
                }
            }       


	            //return value of a certain key
            Tvalue get(Tkey key)
                {
                     struct list_elem<struct elem_info<Tkey, Tvalue> > *p;

                        int hkey = hash(key);
                         p = H[hkey].pfirst;

                         while (p != NULL)
                        {
                            if (p->info.key == key) break;
                            p = p->next;
                        }

                        if (p != NULL)
                            return p->info.value;
                        else
                        {
                            fprintf(stderr, "Error 101 - The key does not exist in the hashtable\n");
                            Tvalue x;
                            return x;
                        }
                }

            //verify if the element with a certain key exists
            int hasKey(Tkey key)
            {
                struct list_elem<struct elem_info<Tkey, Tvalue> > *p;

                int hkey = hash(key);
                p = H[hkey].pfirst;

                while (p != NULL)
                {
                    if (p->info.key == key)
                        break;
                    p = p->next;
                }

                if (p != NULL)
                    return 1;
                else
                    return 0;
            }
};
