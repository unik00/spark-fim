name := "spark-fim"

version := "1.0"

scalaVersion := "2.11.12"

libraryDependencies += "org.apache.spark" %% "spark-core" % "2.4.8"
libraryDependencies += "org.scalatest" %% "scalatest" % "3.0.0" % "test"

// Spark tests cannot be run in parallel
fork in Test := true

// show compilation warnings
scalacOptions ++= Seq("-unchecked", "-deprecation", "-feature")


