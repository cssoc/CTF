DROP TABLE IF EXISTS Users;

CREATE TABLE `Users`
(
	`id` INTEGER AUTO_INCREMENT,
	`username` VARCHAR(50) COLLATE utf8_unicode_ci NOT NULL,
	`password_hash` VARCHAR(100) COLLATE utf8_unicode_ci  NOT NULL,
	`flag` VARCHAR(10),
	PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

INSERT INTO `Users`(`username`, `password_hash`, `flag`)
VALUES
('admin', '0bccdbf6b24bcf5873cc87261a538031d729ca82', 'kujusfbub'), /** 12345653 **/
('other', 'b352db9a93143bf4b6d188d58c7032b1730e946f', 'bksvfbhks'); /** 45678944 **/
