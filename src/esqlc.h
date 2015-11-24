
#ifndef ESQLC_H
#define ESQLC_H

#include <stdint.h>
#include <string>
#include <map>
#include <sqlda.h>


namespace esqlc {

	// forward declarations
	struct cursor_t;

	struct stmt_t {
		std::string id;
		ifx_sqlda_t * sqlda;

		std::string stmt;
		std::map< std::string, cursor_t * > cursors;
	};

	struct cursor_t {
		std::string id;
		stmt_t * stmt;
	};


	int32_t connect( const char * id, const char * database, const char * username = 0, const char * password = 0 );
	int32_t prepare( stmt_t * stmt );
	int32_t run( stmt_t * stmt, cursor_t * cursor );
	int32_t close( stmt_t * stmt );
	int32_t close( cursor_t * cursor );

	std::string errmsg( int32_t code );

}

#endif /* !ESQLC_H */

