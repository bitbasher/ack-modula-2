/* $Id$ */

/*	Get a unique id for C_insertpart, etc.
*/

int C_getid(void)
{
	static int id = 0;

	return ++id;
}
