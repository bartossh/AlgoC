#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int test_score)
{
    if ((1 << allergen) & test_score)
    {
        return true;
    }
    return false;
}

allergen_list_t get_allergens(int test_score)
{
    allergen_list_t list;
    list.count = 0;
    int count = 0; 

    for (allergen_t allergen = ALLERGEN_EGGS; allergen < ALLERGEN_COUNT; allergen++)
    {
        if (is_allergic_to(allergen, test_score))
        {
            list.count++;
            list.allergens[count++] = true;
            continue;
        }
        list.allergens[count++] = false;
    }

    return list;
}
