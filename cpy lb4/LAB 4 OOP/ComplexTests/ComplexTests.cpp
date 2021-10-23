#include "Dog.h"
#include "DynamicArray.h"
#include "gtest/gtest.h"

TEST(Dog, tot)
{
    Dog dg("labrador", "jack", 3, "easws");
    ASSERT_EQ(dg.getAge(), 3);
    ASSERT_EQ(dg.getName(), "jack");
    ASSERT_EQ(dg.getBreed(), "labrador");
    ASSERT_EQ(dg.getPhoto(), "easws");
    ASSERT_NE(dg.toString(), "awsdg fhjf");
}

TEST(DynamicArray, all)
{
    DynamicArray<Dog>(dg);
    DynamicArray<Dog>(dgq);
    ASSERT_EQ(dg.getCapacity(), 2);
    dg.init_array();
    dg.deleteElem("Marta");
    ASSERT_EQ(dg.getLenght(), 9);
    Dog dg1("abc","Chelutu",17,"hjk");
    dg.insertAtEnd(dg1);
    ASSERT_EQ(dg.getLenght(), 9);
    dg.updateElem("Chelutu", "bac", "abb", "4", "htp");
    dg.updateElem("lklk", "qwe","rty", "90", "tto");
    dg.deleteElem("kkp");
    dg.showArray();
    dg.deleteElem("Aky");
    ASSERT_EQ(dg.getLenght(), 8);
    char c[]="9";
    char c1[]="1";
    char c2[]="";
    dg.dog_breed_age("maidanez", c);
    dg.dog_breed_age("maidanez", c1);
    dg.dog_breed_age(c2, c);
    dgq.showArray();

}

TEST(DynamicArrayIterator, all){

    DynamicArray<Dog>(dg);
    ASSERT_EQ(dg.getCapacity(), 2);
    dg.init_array();
    DynamicArrayIterator it = DynamicArrayIterator(dg);
    it.next();
    it.first();
    it.getCurrent();
    it.get_current();

    for (int i = 0; i < 9; i++) {
        it.next();
    }
    ASSERT_EQ(it.get_current(), 9);
    it.next();
    ASSERT_ANY_THROW(it.getCurrent());
    ASSERT_THROW(it.next(), std::exception);
    ASSERT_NO_THROW(it.get_current());
}