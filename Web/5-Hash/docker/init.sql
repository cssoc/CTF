DROP TABLE IF EXISTS Users;
DROP TABLE IF EXISTS Cars;


/** Create Required Tables **/

CREATE TABLE `Users`
(
	`id` INTEGER AUTO_INCREMENT,
	`username` VARCHAR(50) COLLATE utf8_unicode_ci NOT NULL,
	`password_hash` VARCHAR(100) COLLATE utf8_unicode_ci  NOT NULL,
	PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

CREATE TABLE `Cars`
(
	`id` INTEGER AUTO_INCREMENT,
	`brand` VARCHAR(50) COLLATE utf8_unicode_ci NOT NULL,
	`value` INTEGER,
	PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;


/** Populate with admin user **/

INSERT INTO `Users`(`username`, `password_hash`)
VALUES
('admin', '2494832f0f5fb7f6fa87897bc6e81afcb465b44b'); /** vandenende17 **/

