#include<string>
using namespace std;

class Gene{
private:
    string organism,name,sequence;

public:
    Gene(){}
    Gene(string organism,string name,string sequence)
    {
        this->organism = organism;
        this->name = name;
        this->sequence = sequence;
    }
    string get_organism() const
    {
        return this->organism;
    }
    string get_name() const
    {
        return this->name;
    }
    string get_sequence()
    {
        string s = this->sequence;
        return s;
    }
    int get_sequence_length() const
    {
        return this->sequence.length();
    }
    bool includes_sequence(string seq)
    {
        //transf din str in char vect
        char* arr = &this->sequence[0];
        char* arr2 = &seq[0];
        if(strstr(arr,arr2))return true;
        else return false;
    }
    void print_gene() const
    {
        cout<<this->organism<<" | "<<this->name<<" | "<<this->sequence<<endl;
    }
};
