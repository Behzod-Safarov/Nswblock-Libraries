#include "Nsw7SegmentDisplay.h"

// PORT_4 (CLK=9, DIO=8) portidan foydalanamiz
Nsw7SegmentDisplay displey(PORT_4);

void setup() {
    displey.begin();  // Displeyni ishga tushirish
    
    // Birinchi oddiy raqam ko'rsatish
    displey.displayNumber(2023);  // "2023" ni ko'rsatadi (yil)
    delay(2000);  // 2 soniya kutib turadi
    
    // O'nlik raqam ko'rsatish
    displey.display(25.5);  // "25.5" ni ko'rsatadi (xona harorati)
    delay(2000);  // 2 soniya kutib turadi
}

void loop() {
    // Har 2 soniyada raqamlar almashadi
    displey.displayNumber(1234);  // "1234" ni ko'rsatadi
    delay(2000);  // 2 soniya kutib turadi
    
    displey.display(98.6);  // "98.6" ni ko'rsatadi (tana harorati)
    delay(2000);  // 2 soniya kutib turadi
    
    displey.display(-12.3);  // "-12.3" ni ko'rsatadi (sovuq harorat)
    delay(2000);  // 2 soniya kutib turadi
    
    displey.clear();  // Displeyni tozalash
    delay(1000);  // 1 soniya kutib turadi
}