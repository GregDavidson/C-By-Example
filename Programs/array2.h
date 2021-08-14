#ifndef ARRAY_H
#define ARRAY_H

#define ARRAY_SIZE(array) (sizeof (array) / sizeof (array)[0])

#define ARRAY_END(array) (array + ARRAY_SIZE(array))

#define ARRAY_LOOP(pointer, array) \
	for ( (pointer) = (array) ; (pointer) < ARRAY_END(array) ; (pointer)++ )

#endif
