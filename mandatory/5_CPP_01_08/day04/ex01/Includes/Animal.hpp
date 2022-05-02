#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal {
    public:
        Animal(void);
        Animal(Animal const& cpy);
        virtual ~Animal(void);

        Animal&         operator=(Animal const& op);
        void            setType(std::string type);
        std::string     getType(void) const;
        virtual void    makeSound(void) const;

    protected:
        std::string     _type;
};

#endif
