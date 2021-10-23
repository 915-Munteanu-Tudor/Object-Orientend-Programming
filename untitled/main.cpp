#include<bits/stdc++.h>
#include "Gene.h"

using namespace std;
vector<Gene> v;
bool add_gene(Gene g)
{
    //parse the vector to find if the elem is unique
    for(Gene c:v)
        if(c.get_name() == g.get_name() && c.get_organism()==g.get_organism())
            return false;

    v.push_back(g);
    return true;
}
bool sorting_condition(Gene x, Gene y)
{
    //relation used to sort with the inbuilt sort
    return x.get_sequence_length()>y.get_sequence_length();
}

int main()
{
    Gene g1("org1","abc","ATCG"),h("org2","abcd","ATCGT"),g2("org3","abcde","ATTAT"),g3("org4","abcdef","GAGAT");
    add_gene(g1);
    add_gene(h);
    add_gene(g2);
    add_gene(g3);
    while(1)
    {

        char c[50];
        char p1[50],p2[50],p3[50],p4[50];
        cin>>c;
        if(strstr(c,"add_gene"))
        {
            cin>>p1>>p2>>p3;
            Gene g(p1,p2,p3);
            if(add_gene(g))
                cout<<"Gene successfully added!\n";
            else
                cout<<"Gene could not be added!\n";
            strcpy(c,"");
        }
        if(strstr(c,"show_genes"))
        {
            sort(v.begin(),v.end(),sorting_condition);
            for(Gene c:v)
                c.print_gene();
            strcpy(c,"");
        }
        if(strstr(c,"show_all_containing"))
        {
            cin>>p1;
            sort(v.begin(),v.end(),sorting_condition);
            for(Gene c:v)
                if(c.includes_sequence(p1))
                    c.print_gene();
            strcpy(c,"");
        }
        if(strstr(c,"longest_subsequence"))
        {
            string p1,p2,p3,p4;
            cin>>p1>>p2>>p3>>p4;
            Gene g,h;
            for(Gene &c:v)
                if(c.get_organism()==p1 && c.get_name()==p2)
                    for(Gene &c2:v)
                        if(c2.get_organism()==p3 && c2.get_name()==p4)
                        {
                            g = c;
                            h = c2;
                        }
            string s1 = g.get_sequence();
            string s2 = h.get_sequence();
            string auxseq,maxseq;
            for(unsigned int c=0; c<s1.size(); c++)
            {

                for(unsigned int c2=0; c2<s2.size(); c2++)
                {
                    auxseq = "";
                    unsigned int i=0;
                    while(s1[c+i]==s2[c2+i])
                    {
                        auxseq.push_back(s1[c+i]);
                        i++;
                    }
                    if(auxseq.length()>maxseq.length())
                        maxseq = auxseq;
                }

            }
            cout<<maxseq<<endl;
        }
        else if (strstr(c, "exit"))
        {
            break;
        }
    }

    return 0;
}
