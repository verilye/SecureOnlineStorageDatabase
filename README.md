# Design Inspiration and notes

Amazon S3 is the inspiration for what I'm trying to make here.
S3 is like an NOSQL database that can store files
Im specifically going to include the functionality to encrypt files and securely upload and download them
for a bit of extra spice. 

The stages of implementation will be as follows:
Language parser for commands - create groups of objects, upload objects, delete objects etc
Store data objects in locations - allocating storage and potentially recreate cloud backend using my own physical HDD
Protocols for uploading and downloading data
Carrying out crypto operations on the data

Language candidates for each task:
Javascript for web facing portal dashboard
    - Could use something like C# for a desktop app UI
C for parsing commands from user
C for networking shit
C# as a glue language to tie everything together and connect the C and the Javascript???

A learning goal of this endeavour is to understand the intersection of languages more and to 
figure out a personal philosophy of mixing languages across functionality and scope

Other options:
Python


## TODO:

Pick up on the second part of crafting interpreters but dont copy code. Get a rough idea of what Im doing with the code
and write implementation details myself
A good place to start would be writing a list of grammar and then formalising it in some design doc
Write a recursive descent parser in the fastest way possible to handle this grammar

Create the command parser and complete operations on data using the parser. Done locally,inside a single directory. 



### Language parser
a handwritten recursive descent parser seems to be a decent emulation of what people are writing in 
compiling land. It appears to be the fastest option for writing something more advanced than an NOSQL
langugae, therefore it should in theory build my skills better and have more transferrable knowledge
in the long run. 

In my programming lanugage Bungle, I walked the abstract syntax tree directly, but that is a super slow
way of doing things so we want to be doing something tangential but faster with the NOSQL language
interpreter.

Recursive Descent Parser example rough outline
https://www.javatpoint.com/recursive-descent-parser

// Grammar

// The goal of this application is to make an Amazon S3 like application
// Therefore I want to parse commands that are somewhere between NOSQL, SQL and S3 itself

// Interesting SQL Commands
// SELECT, DELETE, UPDATE, INSERT INTO, 

// Interesting S3 Commands
// Create Bucket, List Buckets, List Objects, Delete buckets, Delete objects, Copy objects, Sync objects

// Functionality Wishlist
// transfer between buckets, upload files through web interface, download files, access online files through url and secure code

