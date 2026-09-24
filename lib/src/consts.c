const char* PROVIDES_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS provides ("
"id INTEGER PRIMARY KEY,"
"name TEXT NOT NULL"
");"
;

const char* PACKAGE_PROVIDES_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS package_provides ("
"package_id INTEGER NOT NULL,"
"provides_id INTEGER NOT NULL,"
"FOREIGN KEY(package_id) REFRENCES package(id),"
"FOREIGN KEY(provides_id) REFRENCES provides(id)"
");"
;

const char* PACKAGE_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS package ("
"id INTEGER PRIMARY KEY,"
"name TEXT NOT NULL,"
"description TEXT NOT NULL,"
"architecture INTEGER,"
"published_date INTEGER NOT NULL,"
"version TEXT NOT NULL,"
"license INTEGER,"
"upstream_url TEXT,"
"repository_id INT NOT NULL,"
"metapackage_id INTEGER"
"FOREIGN KEY(repository_id) REFRENCES repository(id),"
"FOREIGN KEY(metapackage_id) REFRENCES metapackage(id)"
");"
;

const char* PACKAGE_DEPENDENCY_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS package_dependeny ("
"package_id INTEGER NOT NULL,"
"dependency_id INTEGER NOT NULL,"
"PRIMARY KEY (package_id, dependency_id),"
"FOREIGN KEY(package_id) REFRENCES package(id),"
"FOREIGN KEY(dependency_id) REFRENCES package(id)"
");"
;

const char* PACKAGE_CONFLICTS_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS package_dependeny ("
"package_id INTEGER NOT NULL,"
"conflicts_id INTEGER NOT NULL,"
"PRIMARY KEY (package_id, conflicts_id),"
"FOREIGN KEY(package_id) REFRENCES package(id),"
"FOREIGN KEY(conflicts_id) REFRENCES package(id)"
");"
;

const char* METAPACKAGE_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS metapackage"
"id INTEGER PRIMARY KEY,"
"name TEXT NOT NULL,"
"description TEXT NOT NULL,"
"architecture INTEGER,"
"published_date INTEGER NOT NULL,"
"version TEXT NOT NULL,"
"repository_id INT NOT NULL,"
");"
;

const char* PACKAGE_GROUP_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS package_provides ("
"package_id INTEGER NOT NULL,"
"group_id INTEGER NOT NULL,"
"FOREIGN KEY(package_id) REFRENCES package(id),"
"FOREIGN KEY(group_id) REFRENCES group(id)"
");"
;

const char* GROUP_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS group"
"id INTEGER PRIMARY KEY,"
"name TEXT NOT NULL,"
"description TEXT NOT NULL,"
"architecture INTEGER,"
"published_date INTEGER NOT NULL,"
"version TEXT NOT NULL,"
"repository_id INT NOT NULL,"
"FOREIGN KEY(repository_id) REFRENCES repository(id)"
");"
;

const char* REPOSITORY_SQL_CREATE_TABLE_STATEMENT = 
"CREATE TABLE IF NOT EXISTS repository ("
"id INTEGER PRIMARY KEY,"
"name TEXT NOT NULL,"
"description TEXT NOT NULL,"
"local INTEGER NOT NULL,"
"url TEXT"
");"
;

const char *YPKG_CONFIG_PATH = "/etc/ypkg.conf";
const char *YPKG_LOCAL_DB = "/var/lib/ypkg/local.db";