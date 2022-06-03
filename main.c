#include <stdio.h>
#include "function.h"

int main()
{
	Human* somebody = Constructor();
	printf("Для этого человека средняя суточная норма калорий равна %.0f.\n", daily_normal_calorie(somebody));
	conscription(somebody);
	printf("Средняя длинна шага этого человека равна %.0f сантиметрам.\n", stride_length(somebody));
	printf("Данному человекe, что бы добиться идеального веса, стоит изменьть его на %.0f кг.\n", ideal_weight(somebody));
	printf("Индекс массы тела этого человека равен %.2f.\n", body_mass_index(somebody));
	Destructor(somebody);
	return 0;
}

