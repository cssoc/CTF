DROP TABLE if exists users;

CREATE TABLE `users` (
  `id` INTEGER AUTO_INCREMENT,
  `username` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `password` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `balance` INTEGER,
  `account` INTEGER,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

INSERT INTO `users` (`username`, `password`, `balance`, `account`) VALUES
('user1', 'password1', 0, 123);

