#pragma once

struct Human;  

typedef struct Human Human;  

//Деструктор структуры Human.
Human* Destructor(Human* obj);

//Конструктор структуры Human.
Human* Constructor();

/*
* @return Средняя суточная доля каллорий.
* @param obj Содержит физические данные человека.
*/
float daily_normal_calorie(Human* obj);

/*
* @return Вычисляет, могут ли человека призвать на срочную службу в армию.
* @param obj Содержит физические данные человека.
*/
void conscription(Human* obj);


/*
* @return Функция вычисляет среднюю длинну шага человека при ходьбе в сантиметрах.
* @param obj Содержит физические данные человека.
*/
float stride_length(Human* obj);


/*
* @return Функция вычисляет сколько человеку нужно набрать/сбросить кг что бы добиться идеального веса.
* @param obj Содержит физические данные человека.
*/
float ideal_weight(Human* obj);

/*
* @return Функция вычисляет индекс массы тела.
* @param obj Содержит физические данные человека.
*/
float body_mass_index(Human* obj);
