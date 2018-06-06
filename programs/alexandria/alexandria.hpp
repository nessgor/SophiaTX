#ifndef STEEM_ALEXANDRIA_HPP
#define STEEM_ALEXANDRIA_HPP

extern "C" {

   /**
    * Generates private_key in WIF format based on random seed.
    * @param private_key - return parameter of size 52
    * @return - true if operation is successful
    */
   bool generate_private_key(char* private_key);

   /**
    * Creates digest of JSON formatted transaction
    * @param transaction - transaction in JSON format
    * @param digest - returned digest of transaction (size 32)
    * @return - true if operation is successful
    */
   bool get_transaction_digest(const char* transaction, char* digest);

   /**
    * Creates signature for provided digest
    * @param digest - digest that will be singed
    * @param private_key  - private key for singing in WIF format
    * @param signed_digest - returned signature (size 65)
    * @return - true if operation is successful
    */
   bool sign_digest(const char* digest, const char* private_key, char* signed_digest);

   /**
    * Adds signature to JSON formatted transaction
    * @param transaction - transaction for singing in JSON format
    * @param signature - signature
    * @param signed_tx - returned signed transaction (size variable, depends on size of transaction on input_
    * @return - true if operation is successful
    */
   bool add_signature(const char* transaction, const char* signature, char* signed_tx);
};

#endif //STEEM_ALEXANDRIA_HPP