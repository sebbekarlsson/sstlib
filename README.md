<div align='center'><img width='128px' src='image.gif'/></div>

# Sebastians Standard Library
> Metal af C standard library for divine intellects.

## ss\_vector
> This vector supports __any__ type that you give it using a little hack
> of mine:

    #include "<sstlib/ss_vector.h>"


    typedef struct APPLE_STRUCT {
        int id;
    } apple;

    apple* init_apple(int id) {
        apple* a;
        a = malloc(sizeof(apple));
        a-> id = id;
        return a;
    };


    int main(int argc, char* argv[]) {
        apple* a = init_apple(0); // hack - temp pointer to use later
        ss_vector* vector = ss_init_vector(a);
        free(a); // hack - free the temp pointer

        for (int i = 0; i < 10; i++)
            ss_vector_append(vector, init_apple(i));


        for (int i = 0; i < vector->size; i++)
            assert_int_equal(((apple*)vector->items[i])->id, i);

        // dont forget to free it
        ss_vector_free(vector);

        return 0;
    }

> Existing methods for `ss_vector`:  
* ss\_init\_vector(void\* type) | _creates a vector_
* ss\_vector\_append(ss\_vector\* vector, void\* item) | _appends an item to vector_
* ss\_vector\_free(ss_vector\* vector) | _free memory for vector_  
> TODO:
* add method for removing item from vector

## ss\_is\_int
> Check if string is int:

    #include <sstlib/ss_strutils.h> // string utils

    ..
    ss_is_int("-16") // 1
    ss_is_int("+16") // 1
    ss_is_int("abc16") // 0
    ..

## More coming soon
> More stuff will be added to this library soon.

## Installation
> To compile and install:

    make
    sudo make install

# Unit tests
> To run the unit tests:

    make
    make test
    ./test.out

> Make sure you have compiled and installed `cmocka` first.
