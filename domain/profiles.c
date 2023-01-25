#include "profiles.h"

#define INSERTION_SORT_THRESHOLD 8

void profiles_quick_sort(Profiles *target, int left, int right, Column column);
void profiles_insert_sort(Profiles *target, int low, int high, Column column);
void profiles_swap_profile(Profiles *target, int from, int to);

void profiles_append(Profiles *target, Profile *value) {
    target->data[target->size] = value;
    target->size += 1;
}

void profiles_sort(Profiles *target, Column column) {
    profiles_quick_sort(target, 0, target->size, column);
}

void profiles_quick_sort(Profiles *target, int left, int right, Column column) {
    int i = left - 1, j = right;
    int length = right - left;

    /*ソートする長さが短ければ挿入ソートに切り替える*/
    if(length <= INSERTION_SORT_THRESHOLD){
        profiles_insert_sort(target, left, right, column);
        return;
    }

    while (1){

        /*右端の文字を基準値として設定*/
        /*左から基準値(右端の文字)より大きい値を探す*/
        while (++i < right && profile_compare_to_profile(target->data[i], target->data[right], column) < 0);

        /*右から基準値(右端の文字)より小さい値を探す*/
        while (profile_compare_to_profile(target->data[right], target->data[--j], column) < 0){

            /*左からの探索と交差すれば終了*/
            if(i >= j) break;
        }

        /*左からの探索と交差すれば終了*/
        if(i >= j) break;
        profiles_swap_profile(target, i, j);
    }

    /*基準値が、左と右の間に入れるように入れ替える*/
    profiles_swap_profile(target, i, right);

    profiles_quick_sort(target, left, i - 1, column);
    profiles_quick_sort(target, i + 1, right, column);
}

void profiles_insert_sort(Profiles *target, int low, int high, Column column) {
    int i, j;

    /*指定された範囲をソート*/
    for(i = low; i <= high; i++){
        /*データの範囲を超えるか、適切な位置になるまで入れ替えを続ける*/
        for(
                j = i;
                (j > low) &&
                (profile_compare_to_profile(target->data[j-1], target->data[j], column) > 0);
                j--){
            profiles_swap_profile(target, j, j-1);
        }
    }
}

void profiles_swap_profile(Profiles *target, int from, int to) {
    Profile *tmp = target->data[from];
    target->data[from] = target->data[to];
    target->data[to] = tmp;
}