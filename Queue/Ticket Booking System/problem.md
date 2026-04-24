TICKET BOOKING SYSTEM - QUEUE

A ticket booking system is used to manage reservations for a limited number of tickets in events, movies, or transportation. Customers arrive in a queue and request a certain number of tickets. The system serves customers in a first-come, first-served order. If there are not enough tickets, the system either partially fulfills the request or rejects it. Implement the queue as a circular array to efficiently reuse memory.

Objective

Must provide the following options:
Add Customer – enqueue a new customer into the queue
Serve Customer – dequeue the first customer and allocate tickets
Display Queue – show all customers in the current queue with requested tickets
Exit – terminate the program
The system should:
Track the total available tickets
Reduce the available tickets when a customer is served
Handle partial allocation if tickets are insufficient
Print messages indicating success, partial allocation, or sold-out status
 

Function Definition

enqueue() -> Adds customer to ticket booking queue
dequeue() -> removes customer from ticket booking queue after serving the customer
serveCustomer() -> removes the first customer from the ticket booking queue and allocates tickets according to their request. It also updates the total available tickets. Print messages for the following scenarios:
Full allocation: The customer's request is fully satisfied.
Partial allocation: Only some of the requested tickets are available. the function allocates what remains.
No tickets left: The request cannot be fulfiled because the tickets are sold out.