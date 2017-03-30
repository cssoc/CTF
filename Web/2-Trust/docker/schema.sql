DROP TABLE if exists users;

CREATE TABLE `users` (
  `id` INTEGER AUTO_INCREMENT,
  `username` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `password` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `privilege` INTEGER,
  `supervisor` varchar(50),
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

INSERT INTO `users` (`username`, `password`, `privilege`, `supervisor`) VALUES
('user1', 'password1', 0, 'admin'),
('admin', 'suhosvo', 1, 'none');

