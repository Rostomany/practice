#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <locale.h>
#include<math.h>

//Структура Human описывает физическое состояние человека.
struct Human
{
	char name[21];	//Имя человека
	int gender;		//Пол человека
	float age;		//Возраст человека
	float weight;		//Вес человека
	float height;		//Рост человека
	int mutilation;	//Наличие или отсутствие увечий, тяжелых болезней.
};


Human* Constructor()  

{
	setlocale(LC_ALL, "Russian");

	Human* obj = (struct Human*)malloc(sizeof(Human));
	if (!obj)
	{
		exit(EXIT_FAILURE);
	}

	printf("Заполните данные:\n");

	printf("Укажите имя (максимум 20 символов):\n");
	fgets(&obj->name, 21, stdin);

	printf("Укажите пол (женщина - 0, Мужчина - 1):\n");
	scanf_s("%i", &obj->gender);

	printf("Укажите возраст:\n");
	scanf_s("%f", &obj->age);

	printf_s("Укажите вес (кг):\n");
	scanf_s("%f", &obj->weight);

	printf("Укажите рост(в сантиметрах):\n");
	scanf_s("%f", &obj->height);

	printf_s("Укажите наличие или отсутствие увечий, тяжелых проблем со здоровьем (нету - 0, есть - 1):\n");
	scanf_s("%i", &obj->mutilation);

	return obj;
}

Human* Destructor(Human* obj)  
{
	free(obj);
}


float daily_normal_calorie(Human* obj) 
{
	float calories = 0;
	if (obj->gender == 0)
		calories = 10 * (obj->weight) + 6.25 * (obj->height) - 5 * (obj->age) - 161;
	else if(obj->gender == 1)
		calories = 10 * (obj->weight) + 6.25 * (obj->height) - 5 * (obj->age) - 5;
	else
		exit(EXIT_FAILURE);
	return calories;
}

void conscription(Human* obj)  
{
	if (obj->mutilation == 1)
		printf("Этого человека не призовут в армию, так как с увечьями, тяжелыми заболеваниями не призывают на срочную службу.\n");
	else if (obj->gender == 0)
		printf("Этого человека не призовут в армию, так как женщин не призывают на срочную службу.\n");
	else if (obj->gender == 1 && obj->age <= 27 && obj->age >= 18)
		printf("Поздравьте этого человека! Он подлежит призыву на срочную службу в армию!\n");
	else if (obj->gender == 1 && (obj->age > 27 || obj->age < 18))
		printf("Этого человека не призовут в армию, так как мужчины до 18 и после 27 не призывают на срочную службу.\n");
	else
		exit(EXIT_FAILURE);
}

float stride_length(Human* obj) 
{
	float length = ((obj->height) / 4) + 37;
	return length;
}

float ideal_weight(Human* obj)
{
	float ideal = 0;
	if (obj->gender == 0)
	{
		ideal = ((obj->height) - 110) * 1.15;
		return (ideal - (obj->weight));
	}
	else if(obj->gender == 1)
	{
		ideal = ((obj->height) - 100) * 1.15;
		return (ideal - (obj->weight));
	}
	else
		exit(EXIT_FAILURE);
}

float body_mass_index(Human* obj)
{
	int index = ((obj->weight) / pow(((obj->height) / 100), 2));
	return index;
}


