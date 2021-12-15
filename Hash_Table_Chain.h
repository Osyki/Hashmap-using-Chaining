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
                hash_fcn(hash<Key_Type>()), num_keys(0),
                the_buckets(INITIAL_CAPACITY),
                LOAD_THRESHOLD(3.00) {}


    /** Inserts an item into the map.
    post: The key is associated with the value in the map.
    @param entry The key, value pair to be inserted
    @return an iterator to the inserted item and true
            if the entry was inserted, an iterator to the existing
            item and false if the item is already present
    */
        std::pair<iterator, bool> insert(const Entry_Type &entry) {
            // Check for the need to rehash.
            double load_factor = double(num_keys) / the_buckets.size();
            if (load_factor > LOAD_THRESHOLD) {
                rehash();
            }

            // Find the position in the table.
            size_t index = hash_fcn(entry.first) % the_buckets.size();


            // Search for the key.
            typename std::list<Entry_Type>::iterator pos = the_buckets[index].begin();

            while (pos != the_buckets[index].end()  && pos->first != entry.first) {
                ++pos;
            }

            if (pos == the_buckets[index].end()) {  // Not in table
                the_buckets[index].push_back(Entry_Type(entry));
                num_keys++;
                return std::make_pair(iterator(this, index, --(the_buckets[index].end())), true);
            } else { // Already there
                return std::make_pair(iterator(this, index, pos), false);
            }
        }

        /** Lookup an item in the map
        @param key The key of the item being sought
        @return An iterator that references a
        pair<const Key_Type, Value_Type> that
        contains the key and the associated value sought,
        or end() if the key is not in the map.
        */
        iterator find(const Key_Type &key) {
            // Find the position in the table
            size_t index = hash_fcn(key) % the_buckets.size();

            // Search for the key
            typename std::list<Entry_Type>::iterator itr = the_buckets.at(index).begin();

            while (itr != the_buckets.at(index).end() && key != itr->first) {
                itr++;
            }

            if (key == itr->first){
                return iterator(this, index, itr);
            } else {
                return this->end();
            }
        }


        /** Lookup an item in the map
        @param key The key of the item being sought
        @return An iterator that references a
        pair<const Key_Type, Value_Type> that
        contains the key and the associated value sought,
        or end() if the key is not in the map.
        */
        const_iterator find(const Key_Type &key) const {
            // Find the position in the table
            size_t index = hash_fcn(key) % the_buckets.size();

            // Search for the key
            typename std::list<Entry_Type>::iterator itr = the_buckets.at(index).begin();

            while (itr != the_buckets.at(index).end() && key != itr->first) {
                itr++;
            }

            if (key == itr->first){
                return iterator(this, index, itr);
            } else {
                return this->end();
            }
        }

        /** Access a value in the map, using the key as an index
        @param key The key of the item being sought
        @return A reference to the associated value. If the
        key was not in the map, a default value is inserted and
        a reference to this value returned.
        */
        Value_Type &operator[](const Key_Type &key) {
            // Try to insert a dummy item
            std::pair<iterator, bool> ret = insert(Entry_Type(key, Value_Type()));
            // Return a reference to the value found or inserted
            return ret.first->second;
        }

        /** Remove an item from the map based on a key
        @param key The key of the item to be removed
        @return true if the item removed, false if the item
        was not already in the map
        */
        bool erase(const Key_Type &key) {
            // Find the position in the table
            size_t index = hash_fcn(key) % the_buckets.size();
            // Search for the key
            typename std::list<Entry_Type>::iterator itr = the_buckets.at(index).begin();

            while (itr != the_buckets.at(index).end()) {
                if (key == itr->first) {
                    the_buckets[index].erase(itr);
                    num_keys--;
                    return true;
                }
            }

            return false;
        }

        /** Return an iterator to the beginning of the map */
        iterator begin() {
            iterator itr(this, 0, the_buckets[0].begin());
            itr.advance();
            return itr;
        }

        /** Return a const_iterator to the beginning of the map */
        const_iterator begin() const {
            const_iterator return_value(this, 0, the_buckets[0].begin());
            return_value.advance();
            return return_value;
        }

        /** Return an iterator to the end of the map */
        iterator end() {
            return iterator(this, the_buckets.size() - 1, the_buckets.at(the_buckets.size() - 1).end());
        }

        /** Return a const_iterator to the end of the map */
        const_iterator end() const {
            const_iterator itr(this, the_buckets.size()-1, the_buckets.at( the_buckets.size()-1 ).end());
            return itr;
        }

        /** Return the size of the map */
        size_t size() const {
            return num_keys;
        }

        /** Determine if the map is empty */
        bool empty() const {
            return the_buckets.empty();
        }

        /** Return a string representation of the hash map
        @return A string that contains each pair enclosed in "[" and "]"
        with the key and value separated by a comma. The whole string
        is enclosed in "{" and "}"
        */
        std::string to_string() const {
            std::ostringstream out;
            out << "{";
            const_iterator itr = this->begin();
            while (itr != this->end()) {
                out << "[" << itr->first << "," << itr->second << "],";
                itr++;
            }

            //hackjob to remove last comma
            std::string tempStr = out.str();
            tempStr.pop_back();
            out.str("");
            out.clear();
            out << tempStr;

            out << "}";
            return out.str();
        }

        // See iterator class
#include "iterator.h"

        // See const_iterator class
#include "const_iterator.h"

    private:

        /** Expand the size of the hash table */
        void rehash() {
            // Create a new table whose size is double the current table.
            std::vector<std::list<Entry_Type>> new_buckets(the_buckets.size() * 2, NULL);
            // Swap this table with the current table.
            the_buckets.swap(new_buckets);
            // Reinsert all items from old table to new.
            for (size_t i = 0; i < new_buckets.size(); i++) {
                typename std::list<Entry_Type>::iterator pos = new_buckets[i].begin();
                while (pos != new_buckets[i].end()) {
                    size_t index = hash_fcn(pos->first) % the_buckets.size();
                    the_buckets[index].push_back(*pos);
                    ++pos;
                }
            }
        }

        /** The hash function object */
        hash<Key_Type> hash_fcn;

        /** The number of items currently in the map */
        size_t num_keys;

        /** Vector of lists containing the buckets */
        std::vector<std::list<Entry_Type> > the_buckets;

        /** The initial capacity */
        static const size_t INITIAL_CAPACITY = 100;

        /** The maximum load factor */
        const double LOAD_THRESHOLD;
    };
}
#endif //CH9_HASHMAP_CHAINING2_HASH_TABLE_CHAIN_H
