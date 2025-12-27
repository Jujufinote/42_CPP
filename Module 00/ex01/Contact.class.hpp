#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
    private :

        std::string fname;
        std::string lname;
        std::string nickname;
        std::string num;
        std::string secret;

	public :

		std::string const	getFname(void) const;
		void				setFname(std::string str);
		std::string const	getLname(void) const;
		void				setLname(std::string str);
		std::string const	getNickname(void) const;
		void				setNickname(std::string str);
		std::string const	getNum(void) const;
		void				setNum(std::string str);
		std::string const	getSecret(void) const;
		void				setSecret(std::string str);

};

#endif
