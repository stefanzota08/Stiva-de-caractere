#include <iostream>
#include <cstring>
using namespace std;
const int nrmax = 101;
class Nod
{
    char info;
    Nod *next;

public:
    Nod(char info, Nod *next = NULL)
    {
        this->info = info;
        this->next = next;
    }
    friend class Stiva_de_caractere;
};
class Stiva_de_caractere
{

private:
    Nod *top;

public:
    Stiva_de_caractere()
    {
        top = NULL;
    }

    Stiva_de_caractere(const Stiva_de_caractere& stiva)
    {
        Nod *aux;
        aux = stiva.top;
        top = NULL;
        while (aux != NULL)
        {
            push(aux->info);
            aux = aux->next;
        }
        reverseSir();

    }
    ~Stiva_de_caractere()
    {
        while(!isEmpty())
        {
            pop();
        }
    }

    void push(char c)
    {
        top = new Nod(c, top);
    }
    char pop()
    {
        if(isEmpty() == false)
        {
            char informatie = top->info;
            Nod *aux = top;
            top = top->next;
            delete aux;
            return informatie;
        }
        else
            return (char)NULL;
    }
    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
    void showTop()
    {
        cout<<top->info<<endl;
    }

    string afisareStiva()
    {
        string resultat = "(top) -> ";
        if(isEmpty())
            resultat = "NULL";
        else
        {
            Nod *curent = top;
            while(curent != NULL)
            {
                resultat = resultat + curent->info + " -> ";
                curent = curent->next;
            }
            resultat = resultat + "NULL";
        }

        return resultat;
    }

    void reverseSir()
    {
        Nod *p, *c, *n;
        p = NULL;
        c = top;
        while( c != NULL )
        {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        top = p;
    }
    friend ostream &operator << (ostream &afisare, Stiva_de_caractere &stiva);
    friend istream &operator >> (istream &citire, Stiva_de_caractere &stiva);
    friend Stiva_de_caractere operator -(Stiva_de_caractere stiva1, Stiva_de_caractere stiva2);

    Stiva_de_caractere operator =(const Stiva_de_caractere& stiva1)
    {
        Stiva_de_caractere temp(stiva1);
        return temp;
    }
};

Stiva_de_caractere operator -(Stiva_de_caractere stiva1, Stiva_de_caractere stiva2)
{
    Stiva_de_caractere temp;

    while (stiva2.isEmpty() == false && stiva1.isEmpty() == false)
    {
        char x = stiva1.pop();
        char y = stiva2.pop();
        if (x >= y)
            temp.push(x);
        else
            temp.push(y);

    }

    return temp;
}

ostream &operator <<(ostream &afisare, Stiva_de_caractere &stiva)
{
    afisare << stiva.afisareStiva() <<endl;
    return afisare;
}

istream &operator >>(istream &citire, Stiva_de_caractere &stiva)
{
    char s[nrmax];
    citire.get(s,nrmax);
    for (int i=0; i<strlen(s); i++)
        stiva.push(s[i]);
    return citire;
}


int main()
{
    Stiva_de_caractere stiva1;
    Stiva_de_caractere stiva2;
    cout<<"Introduceti caracterele fara spatiu intre ele: ";
    Stiva_de_caractere diferenta;
    Stiva_de_caractere stiva3;
    cin>>stiva1;
    stiva1.showTop();

    stiva2.push('a');
    stiva2.push('b');
    stiva2.push('c');
    stiva2.showTop();

    cout<<stiva1<<endl;
    cout<<stiva2<<endl;

    stiva2 = stiva3; //nu merge sa folosesc atribuirea

    cout<<stiva3<<endl; // afiseaza null pentru ca nu merge atribuirea
    stiva3.reverseSir();

    cout<<stiva2<<endl;
    cout<<stiva3<<endl; // la fel si aici
    //diferenta = stiva1;
    //cout<<diferenta<<endl;
    return 0;
}
