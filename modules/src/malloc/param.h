#include	"size_type.h"

/*#	define	NON_STANDARD	/*	If defined, the contents of a block
					will NOT be left undisturbed after it
					is freed, as opposed to what it says
					in the manual (malloc(2)).
					Setting this option reduces the memory
					overhead considerably.  I personally
					consider the specified behaviour an
					artefact of the original
					implementation.
				*/

/*#	define	ASSERT		/*	If defined, some inexpensive tests
					will be made to ensure the
					correctness of some sensitive data.
					It often turns an uncontrolled crash
					into a controlled one.
				*/

/*#	define	CHECK		/*	If defined, extensive and expensive
					tests will be done, inculding a
					checksum on the mallinks (chunk
					information blocks).  The resulting
					information will be printed on a file
					called mal.out .
					Additionally a function
						maldump(n) int n;
					will be defined, which will dump
					pertinent info in pseudo-readable
					form; it aborts afterwards if n != 0.
				*/

/*#	define	EXTERN		/*	If defined, all static names will
					become extern, which is a help in
					using adb(1) or prof(1)
				*/

#	define	STORE		/*	If defined, separate free lists will
					be kept of chunks with small sizes,
					to speed things up a little.
				*/

#	define SYSTEM		/*	If defined, the system module is used.
					Otherwise, "sbrk" is called directly.
				*/

#define	ALIGNMENT	8	
				/* alignment common to all types */
#define	LOG_MIN_SIZE	3
#define	LOG_MAX_SIZE	24
