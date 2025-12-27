#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.class.hpp"

class PhoneBook
{
    private :
        Contact tablo[8];
        int     i;

    public :
		PhoneBook(void);
        void add(Contact contact);
        void printphonebook(void);
		void search(int index);
};

#endif
