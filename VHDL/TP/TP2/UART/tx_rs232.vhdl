library IEEE;
    use IEEE.STD_LOGIC_1164.all;
    use IEEE.NUMERIC_STD.all;
    use IEEE.STD_LOGIC_UNSIGNED.all;

-- BLOCK: Baudrate --

entity tx_rs232 is
    Port ( clk : in STD_LOGIC;
           write_d : in STD_LOGIC;
           data_o : in STD_LOGIC_VECTOR;
           top_tx : in STD_LOGIC;
           tx : out STD_LOGIC;
           busy : out STD_LOGIC);
end tx_rs232;

architecture Behavioral of Baudrate is
    type etat_type is (attente, chargement, synchro, envoi, fin);
    signal etat, etat_suiv : etat_type := attente;
    signal tx_reg : STD_LOGIC_VECTOR(9 downto 0);
    signal nb_bits : STD_LOGIC_VECTOR(3 downto 0) := "0000";

begin

SYNC : process(clk)
begin
    if rising_edge(clk) then
        etat <= etat_suiv;
        if etat = chargement then
            tx_reg <= '1' & data_o & '0';
            nb_bits <= "0000";
        elsif etat = envoi and top_tx = '1' then
            tx_reg <= '1' & tx_reg(9 downto 1);
            nb_bits <= nb_bits + 1;
        end if;
    end if;
end process;

COMB : process(etat, write_d, nb_bits, top_tx)
begin
    case etat is
        when attente =>
            tx <= '1';
            busy <= '0';
            if write_d = '1' then
                etat_suiv <= chargement;
            else
                etat_suiv <= attente;
            end if;
        when chargement =>
            tx <= '1';
            busy <= '1';
            etat_suiv <= synchro;
        when synchro =>
            tx <= '1';
            busy <= '1';
            if top_tx = '1' then
                etat_suiv <= envoi;
            else
                etat_suiv <= synchro;
            end if;
        when envoi =>
            tx <= tx_reg(0);
            busy <= '1';
            if top_tx = '1' and nb_bits = "1010" then
                etat_suiv <= fin;
            else
                etat_suiv <= envoi;
            end if;
        when synchro =>
            tx <= '1';
            busy <= '1';
            if top_tx = '1' then
                etat_suiv <= attente;
            else
                etat_suiv <= fin;
            end if;
    end case;
end process;

end Behavioral;
