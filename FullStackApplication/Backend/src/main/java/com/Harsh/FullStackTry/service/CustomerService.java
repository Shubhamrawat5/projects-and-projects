package com.Harsh.FullStackTry.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.Harsh.FullStackTry.exceptions.UserNotFoundException;
import com.Harsh.FullStackTry.model.Customer;
import com.Harsh.FullStackTry.repositry.custRepo;

@Service
public class CustomerService {
	
	private final custRepo custrepo;
	@Autowired
	public CustomerService(custRepo custrepo) {
		this.custrepo = custrepo;
	}
	public Customer addCust(Customer customer) {
		return custrepo.save(customer);
	}
	public List<Customer> findAll(){
		return custrepo.findAll();
	}
	public Customer find(long id) {
		return custrepo.findById(id).orElseThrow(()->new UserNotFoundException ("User By "+ id + " Was Not Found"));
	}
	public Customer update(Customer customer) {
		return custrepo.save(customer);
	}
	public void delete(long id) {
		custrepo.deleteById(id);
	}
}
