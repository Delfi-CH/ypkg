const char *SQL_CREATE_REPOSITORY = 
    "CREATE TABLE IF NOT EXISTS repository ("
    "id INT PRIMARY KEY,"
    "name TEXT UNIQUE NOT NULL,"
    "description TEXT NOT NULL,"
    "local INT NOT NULL DEFAULT 0,"
    "last_updated INTEGER NOT NULL,"
    "url TEXT NOT NULL,"
    "package_count INTEGER NOT NULL"
    ");"
;

const char *SQL_CREATE_PACKAGE_IDENTIFIER = 
    "CREATE TABLE IF NOT EXISTS package_identifier ("
    "id INTEGER PRIMARY KEY,"
    "name TEXT UNIQUE NOT NULL,"
    "description TEXT NOT NULL,"
    "architecture INTEGER NOT NULL,"
    "published_date INTEGER NOT NULL,"
    "version TEXT NOT NULL"
    ");"
;

const char *SQL_CREATE_PACKAGE_IDENTIFIER_REPOSITORY = 
    "CREATE TABLE IF NOT EXISTS package_identifier_repository ("
    "package_id INTEGER NOT NULL,"
    "repository_id INTEGER NOT NULL,"
    "PRIMARY KEY (package_id, repository_id),"
    "FOREIGN KEY(package_id) REFERENCES package_identifier(id),"
    "FOREIGN KEY(repository_id) REFERENCES repository(id)"
    ");"
;

const char *SQL_CREATE_PROVIDES =
    "CREATE TABLE IF NOT EXISTS provides ("
    "id INTEGER PRIMARY KEY,"
    "name TEXT NOT NULL"
    ");"
;

const char *SQL_CREATE_PACKAGE =
    "CREATE TABLE IF NOT EXISTS package ("
    "self_id INTEGER PRIMARY KEY,"
    "id INTEGER NOT NULL,"
    "license INTEGER NOT NULL,"
    "upstream_url TEXT NOT NULL,"
    "metapackage_id INTEGER,"
    "FOREIGN KEY(id) REFERENCES package_identifier(id)"
    ");"
;

const char *SQL_CREATE_PACKAGE_PROVIDES =
    "CREATE TABLE IF NOT EXISTS package_provides ("
    "package_id INTEGER NOT NULL,"
    "provides_id INTEGER NOT NULL,"
    "PRIMARY KEY (package_id, provides_id),"
    "FOREIGN KEY(package_id) REFERENCES package(self_id),"
    "FOREIGN KEY(provides_id) REFERENCES provides(id)"
    ");"
;

const char *SQL_CREATE_PACKAGE_DEPENDS =
    "CREATE TABLE IF NOT EXISTS package_dependency ("
    "package_id INTEGER NOT NULL,"
    "dependency_id INTEGER NOT NULL,"
    "PRIMARY KEY (package_id, dependency_id),"
    "FOREIGN KEY(package_id) REFERENCES package(self_id),"
    "FOREIGN KEY(dependency_id) REFERENCES package(self_id)"
    ");"
;

const char *SQL_CREATE_PACKAGE_CONFLICTS =
    "CREATE TABLE IF NOT EXISTS package_conflicts ("
    "package_id INTEGER NOT NULL,"
    "conflicts_id INTEGER NOT NULL,"
    "PRIMARY KEY (package_id, conflicts_id),"
    "FOREIGN KEY(package_id) REFERENCES package(self_id),"
    "FOREIGN KEY(conflicts_id) REFERENCES package(self_id)"
    ");"
;

const char *SQL_CREATE_METAPACKAGE = 
    "CREATE TABLE IF NOT EXISTS metapackage ("
    "self_id INTEGER PRIMARY KEY,"
    "id INTEGER NOT NULL,"
    "FOREIGN KEY(id) REFERENCES package_identifier(id)"
    ");"
;

const char *SQL_CREATE_PACKAGE_METAPACKAGE = 
    "CREATE TABLE IF NOT EXISTS package_metapackage ("
    "package_id INT NOT NULL,"
    "metapackage_id INT NOT NULL,"
    "PRIMARY KEY (package_id, metapackage_id),"
    "FOREIGN KEY(package_id) REFERENCES package(self_id),"
    "FOREIGN KEY(metapackage_id) REFERENCES metapackage(self_id)"
    ");"
;

const char *SQL_CREATE_GROUP = 
    "CREATE TABLE IF NOT EXISTS package_group ("
    "self_id INTEGER PRIMARY KEY,"
    "id INTEGER NOT NULL,"
    "FOREIGN KEY(id) REFERENCES package_identifier(id)"
    ");"
;

const char *SQL_CREATE_PACKAGE_GROUP = 
    "CREATE TABLE IF NOT EXISTS package_package_group ("
    "package_id INT NOT NULL,"
    "group_id INT NOT NULL,"
    "PRIMARY KEY (package_id, group_id),"
    "FOREIGN KEY(package_id) REFERENCES package(self_id),"
    "FOREIGN KEY(group_id) REFERENCES package_group(self_id)"
    ");"
;

const char *YPKG_CONFIG_PATH = "/etc/ypkg.conf";
const char *YPKG_LOCAL_DB = "/var/lib/ypkg/local.db";