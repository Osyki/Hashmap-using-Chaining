//
// Created by Ekyso on 12/14/2021.
//

#ifndef CH9_HASHMAP_CHAINING2_HASH_TABLE_CHAIN_H
#define CH9_HASHMAP_CHAINING2_HASH_TABLE_CHAIN_H

#include <stdexcept>
#include <cstddef>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <ostream>
#include "hash.h"

namespace KW {
/** Definition of the hash_map class. This definition is similar
to the unordered_map that has been proposed for the next
version of the C++ standard.
@param Key_Type The type of the keys
@param Value_Type The type of the values
*/
    template<typename Key_Type, typename Value_Type>
    class hash_map {

    public:
        // Typedefs
        typedef std::pair<const Key_Type, Value_Type> Entry_Type;

        // Forward declaration of iterator
        class iterator;

        class const_iterator;

        /** Construct an empty hash_map. */
        hash_map() :
            hash_fcn(hash<Key_Type>()),
            the_buckets(INITIAL_CAPACITY),
            LOAD_THRESHOLD(0.75) {}


/** Inserts an item into the map.
    post: The key is associated with the value in the map.
    @param entry The key, value pair to be inserted
    @return an iterator to the inserted item and true
            if the entry was inserted, an iterator to the existing
            item and false if the item is already present
*/
        std::pair<iterator, bool>
        insert(const Entry_Type &entry) {
            /*</exercise>*/
            // Check for the need to rehash.

            // Find the position in the table.

            // Search for the key.
        }

        /** Lookup an item in the map
        @param key The key of the item being sought
        @return An iterator that references a
        pair<const Key_Type, Value_Type> that
        contains the key and the associated value sought,
        or end() if the key is not in the map.
        */
        iterator find(const Key_Type &key) {
            /*<exercise>*/
            // Find the position in the table

            // Search for the key

        }


        /** Lookup an item in the map
        @param key The key of the item being sought
        @return An iterator that references a
        pair<const Key_Type, Value_Type> that
        contains the key and the associated value sought,
        or end() if the key is not in the map.
        */
        const_iterator find(const Key_Type &key) const {
            /*<exercise>*/
            // Find the position in the table

            // Search for the key

            /*</exercise>*/
        }

        /** Access a value in the map, using the key as an index
        @param key The key of the item being sought
        @return A reference to the associated value. If the
        key was not in the map, a defalut value is inserted and
        a reference to this value returned.
        */
        Value_Type &operator[](const Key_Type &key) {
            // Try to insert a dummy item

            // Return a reference to the value found or inserted

        }

        /** Remove an item from the map based on a key
        @param key The key of the item to be removed
        @return true if the item removed, false if the item
        was not already in the map
        */
        bool erase(const Key_Type &key) {
            /*<exercise chapter="9" section="4" type="programming" number="2">*/
            // Find the position in the table

            // Search for the key

            /*</exercise>*/
        }

        /** Return an iterator to the beginning of the map */
        iterator begin() {

        }

        /** Return a const_iterator to the beginning of the map */
        const_iterator begin() const {

        }

        /** Return an iterator to the end of the map */
        iterator end() {
        }

        /** Return a const_iterator to the end of the map */
        const_iterator end() const {
        }

        /*<exercise chapter="9" section="4" type="programming" number="5">*/
        /** Return the size of the map */
        size_t size() const {
            /*</exercise>*/
        }

        /** Determine if the map is empty */
        bool empty() const {
            /*</exercise>*/
        }

        /*</exercise chapter="9" section="4" type="programming" number="3">*/
        /** Return a string representation of the hash map
        @return A string that contains each pair enclosed in "[" and "]"
        with the key and value separated by a comma. The whole string
        is enclosed in "{" and "}"
        */
        std::string to_string() const {
            /*</exercise>*/
        }

        // See iterator class
        /*</exercise>*/
#include "iterator.h"

        // See const_iterator class
        /*</exercise>*/
#include "const_iterator.h"

    private:

/** Expand the size of the hash table */
        void rehash() {
            /*<exercise chapter="9" section="4" type="programming" number="2">*/
            // Create a new table that is twice the size

            // Swap tables

            // Reinsert items from old table to new one

            /*</exercise>*/
        }

// Insert data fields here
/** The hash function object */
        std::hash<Key_Type> hash_fcn;

/** The number of items currently in the map */
        size_t num_keys;

/** Vector of lists containing the buckets */
        std::vector<std::list<Entry_Type> > the_buckets;

/** The initial capacity */
        static const size_t INITIAL_CAPACITY = 20;

/** The maximum load factor */
        const double LOAD_THRESHOLD;
    };
}
#endif //CH9_HASHMAP_CHAINING2_HASH_TABLE_CHAIN_H
