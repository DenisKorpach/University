CREATE DATABASE  IF NOT EXISTS `kursov` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `kursov`;
-- MySQL dump 10.13  Distrib 8.0.34, for Win64 (x86_64)
--
-- Host: localhost    Database: kursov
-- ------------------------------------------------------
-- Server version	8.0.34

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `билет_`
--

DROP TABLE IF EXISTS `билет_`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `билет_` (
  `ID_Билета` int NOT NULL,
  `Тип_билета` varchar(50) DEFAULT NULL,
  `Цена` decimal(10,2) DEFAULT NULL,
  `Дата_и_время_покупки` datetime DEFAULT NULL,
  `Посетитель_ID` int DEFAULT NULL,
  `Экскурсия_ID` int DEFAULT NULL,
  PRIMARY KEY (`ID_Билета`),
  KEY `Посетитель_ID` (`Посетитель_ID`),
  KEY `Экскурсия_ID` (`Экскурсия_ID`),
  CONSTRAINT `билет__ibfk_1` FOREIGN KEY (`Посетитель_ID`) REFERENCES `посетитель` (`ID_Посетителя`) ON DELETE SET NULL ON UPDATE CASCADE,
  CONSTRAINT `билет__ibfk_2` FOREIGN KEY (`Экскурсия_ID`) REFERENCES `экскурсия_` (`ID_Экскурсии`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `билет_`
--

LOCK TABLES `билет_` WRITE;
/*!40000 ALTER TABLE `билет_` DISABLE KEYS */;
/*!40000 ALTER TABLE `билет_` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `гид`
--

DROP TABLE IF EXISTS `гид`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `гид` (
  `ID_Гида` int NOT NULL,
  `Имя` varchar(50) DEFAULT NULL,
  `Фамилия` varchar(50) DEFAULT NULL,
  `Специализация` varchar(100) DEFAULT NULL,
  `Контактная_информация` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`ID_Гида`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `гид`
--

LOCK TABLES `гид` WRITE;
/*!40000 ALTER TABLE `гид` DISABLE KEYS */;
INSERT INTO `гид` VALUES (7,'7','7','7','7'),(8,'8','8','8','8');
/*!40000 ALTER TABLE `гид` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `посетитель`
--

DROP TABLE IF EXISTS `посетитель`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `посетитель` (
  `ID_Посетителя` int NOT NULL,
  `Имя` varchar(50) DEFAULT NULL,
  `Фамилия` varchar(50) DEFAULT NULL,
  `Дата_рождения` date DEFAULT NULL,
  `Контактная_информация` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`ID_Посетителя`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `посетитель`
--

LOCK TABLES `посетитель` WRITE;
/*!40000 ALTER TABLE `посетитель` DISABLE KEYS */;
INSERT INTO `посетитель` VALUES (4,'4','4','4044-04-04','4'),(5,'5','5','5055-05-05','6'),(6,'6','6','6066-06-06','6');
/*!40000 ALTER TABLE `посетитель` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `экскурсия_`
--

DROP TABLE IF EXISTS `экскурсия_`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `экскурсия_` (
  `ID_Экскурсии` int NOT NULL,
  `Название` varchar(100) DEFAULT NULL,
  `Дата_и_время_начала` datetime DEFAULT NULL,
  `Гид_ID` int DEFAULT NULL,
  PRIMARY KEY (`ID_Экскурсии`),
  KEY `Гид_ID` (`Гид_ID`),
  CONSTRAINT `экскурсия__ibfk_1` FOREIGN KEY (`Гид_ID`) REFERENCES `гид` (`ID_Гида`) ON DELETE SET NULL ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `экскурсия_`
--

LOCK TABLES `экскурсия_` WRITE;
/*!40000 ALTER TABLE `экскурсия_` DISABLE KEYS */;
INSERT INTO `экскурсия_` VALUES (1,'1','2023-11-15 10:00:00',7),(2,'Эия 1','2023-11-15 10:00:00',7),(3,'3','2023-12-16 11:00:05',7),(5,'gfgf','2023-12-16 11:00:15',7);
/*!40000 ALTER TABLE `экскурсия_` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `экскурсия_экспонат`
--

DROP TABLE IF EXISTS `экскурсия_экспонат`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `экскурсия_экспонат` (
  `Экскурсия_ID` int DEFAULT NULL,
  `Экспонат_ID` int DEFAULT NULL,
  KEY `Экскурсия_ID` (`Экскурсия_ID`),
  KEY `Экспонат_ID` (`Экспонат_ID`),
  CONSTRAINT `экскурсия_экспонат_ibfk_1` FOREIGN KEY (`Экскурсия_ID`) REFERENCES `экскурсия_` (`ID_Экскурсии`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `экскурсия_экспонат_ibfk_2` FOREIGN KEY (`Экспонат_ID`) REFERENCES `экспонат` (`ID_Экспоната`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `экскурсия_экспонат`
--

LOCK TABLES `экскурсия_экспонат` WRITE;
/*!40000 ALTER TABLE `экскурсия_экспонат` DISABLE KEYS */;
INSERT INTO `экскурсия_экспонат` VALUES (1,1),(1,2),(2,1),(3,3);
/*!40000 ALTER TABLE `экскурсия_экспонат` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `экспонат`
--

DROP TABLE IF EXISTS `экспонат`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `экспонат` (
  `ID_Экспоната` int NOT NULL,
  `Название` varchar(100) DEFAULT NULL,
  `Описание` text,
  `Автор` varchar(50) DEFAULT NULL,
  `Тип` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`ID_Экспоната`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `экспонат`
--

LOCK TABLES `экспонат` WRITE;
/*!40000 ALTER TABLE `экспонат` DISABLE KEYS */;
INSERT INTO `экспонат` VALUES (1,'1','1','1','1'),(2,'2','2','2','2'),(3,'3','3','3','3');
/*!40000 ALTER TABLE `экспонат` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'kursov'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-12-05 17:27:13
