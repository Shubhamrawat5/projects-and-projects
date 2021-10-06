package com.Harsh.FullStackTry;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.Harsh.FullStackTry.model.Customer;
import com.Harsh.FullStackTry.service.CustomerService;

@RestController
@RequestMapping("/customer")
public class CustomerController {
	
	private final CustomerService customerservice;
	@Autowired
	public CustomerController(CustomerService customerservice) {
		this.customerservice = customerservice;
	}
	@GetMapping("/all")
	public ResponseEntity<List<Customer>> findAll(){
		List<Customer> customers = customerservice.findAll();
		return new ResponseEntity<>(customers,HttpStatus.OK);
	}
	@GetMapping("/find/{id}")
	public ResponseEntity<Customer> find(@PathVariable("id") long id){
		Customer customer = customerservice.find(id);
		return new ResponseEntity<>(customer,HttpStatus.OK);
	}
	@PostMapping("/add")
	public ResponseEntity<Customer> add(@RequestBody Customer customer){
		Customer newCust = customerservice.addCust(customer);
		return new ResponseEntity<>(newCust,HttpStatus.CREATED);
	}
	@PutMapping("/update")
	public ResponseEntity<Customer> update(@RequestBody Customer customer){
		Customer updCust = customerservice.update(customer);
		return new ResponseEntity<>(updCust,HttpStatus.OK);
	}
	@DeleteMapping("/delete/{id}")
	public ResponseEntity<?> delete(@PathVariable long id){
		customerservice.delete(id);
		return new ResponseEntity<>(HttpStatus.OK);
	}
}
